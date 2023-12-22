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

	// 외적값이 양수 == 양수각 == 반시계방향
	if (ccw > 0)
		return true;
	// 외적값이 음수 == 음수각 == 시계방향
	else if (ccw < 0)
		return false;
}

int IsInsidePolygon(const vector<Point>& polygon, const Point& point, const Point& point2)
{
	int intersectCount = 0;				 // 교차점 개수
	int n = polygon.size();				 // 다각형의 꼭짓점 개수

	// 다각형의 "각 변"과 "주어진 점"을 비교하여 교차점 개수를 센다
	for (int i = 0; i < n; i++) {		 // i는 선분의 시작점
		int j = (i + 1) % n;			 // j는 선분의 끝점

		/// 프리패스 Safe

		// 점이 꼭짓점에 있는 경우
		if (polygon[i].x == point.x && polygon[i].y == point.y) {
			return 1;
		}
		else if (polygon[j].x == point.x && polygon[j].y == point.y) {
			return 1;
		}

		// 점이 선분 위에 있는 경우
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
		// 평행한 경우

		/// 교차점 개수 세기

		if (IsIntersect(polygon[i], polygon[j], point))
			intersectCount++;			 // 교차점 개수 증가
	}

	// 교차점 개수가 홀수이면 좌표가 다각형 내부에 있다
	return (intersectCount % 2 == 1);
}

int main()
{
	// 방어막의 꼭짓점 개수
	int vertexCount; cin >> vertexCount;

	// 방어막의 꼭짓점(x, y)를 저장할 컨테이너 선언
	vector<Point> polygon;
	vector<Point> friendPos;

	// 다각형의 꼭짓점 좌표
	for (int i = 0; i < vertexCount; ++i)
	{
		int a; cin >> a;
		int b; cin >> b;

		polygon.push_back(Point{ a, b });
	}

	// 대연 영훈 범진의 좌표
	for (int i = 0; i < 3; ++i)
	{
		int a; cin >> a;
		int b; cin >> b;

		friendPos.push_back(Point{ a, b });
	}

	// 대연 영훈 범진의 좌표 각각에서 Ray를 쏘아, 방어막(다각형) 안에 있는지 확인한다
		// 세 줄에 입력된 순서대로 테러에서 막아줄 수 있으면 1, 없으면 0을 출력한다.
	for (auto pos : friendPos)
		cout << IsInsidePolygon(polygon, pos, Point{std::numeric_limits<int>::max(), pos.y}) << endl;

	return 0;
}