#include <iostream>
#include <vector>

using namespace std;

struct Point
{
	int x;
	int y;
};

int CCW(const Point& A, const Point& B)
{
	// A X B = |A||B|sin(theta)
	// ���� ���� ���Ѵ�

	// ������ == ��Ľ� ��
	int cross = A.x * B.y - A.y * B.x;

	// ��Ľ� ���� ������� theta�� ������ (�ð� ����)
	if (cross < 0)
	{
		// �ð� ����
		return -1;
	}
	// ��Ľ� ���� ������ theta�� ����� (�ݽð� ����)
	else if(cross > 0)
	{
		// �ݽð� ����
		return 1;
	}
	else
	{
		// ����
		return 0;
	}
}

int main()
{
	// ù° �ٿ� P1�� (x1, y1), ��° �ٿ� P2�� (x2, y2), ��° �ٿ� P3�� (x3, y3)�� �־�����.
	vector<Point> point;
	point.resize(3);

	for(Point& v : point)
	{
		cin >> v.x;
		cin >> v.y;
	}

	Point vector1 = {point[1].x - point[0].x, point[1].y - point[0].y};
	Point vector2 = {point[2].x - point[1].x, point[2].y - point[1].y};

	// cout<< vector1.x << " " << vector1.y << endl;
	// cout<< vector2.x << " " << vector2.y << endl;

	cout << CCW(vector1, vector2) << endl;











	/*
	// Print
	for(auto v : point)
	{
		cout << v.x << " " << v.y << endl;
	}
	*/



	return 0;
}