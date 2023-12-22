// ReSharper disable All
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct Point
{
	int x;
	int y;
};

float CCW(const Point& p1, const Point& p2, const Point& p3)
{
	return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y)
		- (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}

bool IsIntersect(const Point& p1, const Point& p2, const Point& p3)
{
	int ccw = CCW(p1, p2, p3);

	// �������� ��� == ����� == �ݽð����
	if (ccw > 0)
		return true;
	// �������� ���� == ������ == �ð����
	else if (ccw < 0)
		return false;
}

int IsInsidePolygon(const vector<Point>& polygon, const Point& point, const Point& point2)
{
	int intersectCount = 0;				 // ������ ����
	int n = polygon.size();				 // �ٰ����� ������ ����

	// �ٰ����� "�� ��"�� "�־��� ��"�� ���Ͽ� ������ ������ ����
	for (int i = 0; i < n; i++) {		 // i�� ������ ������
		int j = (i + 1) % n;			 // j�� ������ ����

		/// �����н� Safe

		// ���� �������� �ִ� ���
		if (polygon[i].x == point.x && polygon[i].y == point.y) {
			return 1;
		}
		else if (polygon[j].x == point.x && polygon[j].y == point.y) {
			return 1;
		}

		// ���� ���� ���� �ִ� ���
		if (CCW(polygon[i], polygon[j], point) == 0) {

			if(polygon[i].x > polygon[j].x)
			{
				if (polygon[i].x > point.x && polygon[j].x < point.x)
					return 1;
			}
			else if (polygon[i].x < polygon[j].x)
			{
				if (polygon[i].x < point.x && polygon[j].x > point.x)
					return 1;
			}
			else
			{
				if (polygon[i].x == point.x && polygon[i].x == point.x)
					return 1;
			}

		}
		// ������ ���

		/// ������ ���� ����

		if (IsIntersect(polygon[i], polygon[j], point))
			intersectCount++;			 // ������ ���� ����
	}

	// ������ ������ Ȧ���̸� ��ǥ�� �ٰ��� ���ο� �ִ�
	return (intersectCount % 2 == 1);
}

int main()
{
	// ���� ������ ����
	int vertexCount; cin >> vertexCount;

	// ���� ������(x, y)�� ������ �����̳� ����
	vector<Point> polygon;
	vector<Point> friendPos;

	// �ٰ����� ������ ��ǥ
	for (int i = 0; i < vertexCount; ++i)
	{
		int a; cin >> a;
		int b; cin >> b;

		polygon.push_back(Point{ a, b });
	}

	// �뿬 ���� ������ ��ǥ
	for (int i = 0; i < 3; ++i)
	{
		int a; cin >> a;
		int b; cin >> b;

		friendPos.push_back(Point{ a, b });
	}

	// �뿬 ���� ������ ��ǥ �������� Ray�� ���, ��(�ٰ���) �ȿ� �ִ��� Ȯ���Ѵ�
		// �� �ٿ� �Էµ� ������� �׷����� ������ �� ������ 1, ������ 0�� ����Ѵ�.
	for (auto pos : friendPos)
		cout << IsInsidePolygon(polygon, pos, Point{std::numeric_limits<int>::max(), pos.y}) << endl;

	return 0;
}