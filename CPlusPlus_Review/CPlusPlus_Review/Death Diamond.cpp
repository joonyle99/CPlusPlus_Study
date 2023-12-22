#include <iostream>

using namespace std;

class Base
{
public:
	int a;	// Drived1에 갈 수도
			// Drived2에 갈 수도 있다.

};

class Drived1 : virtual public Base
{

};

class Drived2 : virtual public Base
{

};

class DDrived : public Drived1, public Drived2
{
public:
	void AccessBothInstance()
	{
		Drived1::a = 1;
		Drived2::a = 2;
	}

	void PrintBothInstance()
	{
		cout << Drived1::a << endl;
		cout << Drived2::a << endl;
	}
};

int main()
{
	DDrived dd;

	// 이 예시는 같은 Base 클래스의 멤버 변수에 대해 두 개의 서로 다른 값이 존재한다는 것을 보여줍니다.
	// 이것이 바로 "죽음의 다이아몬드" 구조에서 발생하는 주요 문제입니다.

	// 서로 다른 a가 2개가 존재하는 상황이 온다.

	dd.AccessBothInstance();
	dd.PrintBothInstance();	// Drived1::a = 1
							// Drived2::a = 2

	/// 해결을 위해
	// "가상 상속"을 사용한다.
	// 상속 시 virtual을 붙힌다.

	// Drived1::a = 1
	// Drived2::a = 2

	// Drived1의 a / Drived2의 a가 아닌,
	// Base의 a로 통일시키는 것이다


}