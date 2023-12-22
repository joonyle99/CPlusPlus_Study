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
	// 외적 값을 구한다

	// 외적값 == 행렬식 값
	int cross = A.x * B.y - A.y * B.x;

	// 행렬식 값이 음수라면 theta가 음수각 (시계 방향)
	if (cross < 0)
	{
		// 시계 방향
		return -1;
	}
	// 행렬식 값이 양수라면 theta가 양수각 (반시계 방향)
	else if(cross > 0)
	{
		// 반시계 방향
		return 1;
	}
	else
	{
		// 평행
		return 0;
	}
}

int main()
{
	// 첫째 줄에 P1의 (x1, y1), 둘째 줄에 P2의 (x2, y2), 셋째 줄에 P3의 (x3, y3)가 주어진다.
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