#include <iostream>

int main()
{
	// auto 키워드는 "컴파일 타임"에 타입이 추론된다

	auto integer = 4;
	auto floating = 4.5f;
	auto doubling = 4.5;
	auto charr = 'c';

	int* pInteger = &integer;
	auto* aPInteger = pInteger;	// auto는 int 타입
									// 포인터를 전달받을때는 auto*를 이용한다 (auto 자체가 int*이 됨)

	int& rInteger = integer;
	auto& aRInteger = rInteger;	// auto는 int 타입
									// 참조를 전달받을때는 auto&를 이용한다 (참조를 전달받을 수 없기 때문에)

	auto aRInteger_nonRefKeyword = rInteger;	// auto&를 해주지 않으면 참조 레퍼런스가 적용되지 않고 새로운 메모리에 할당된다

	using std::cout;
	using std::endl;

	cout << "integer's address : " << &integer << endl;
	cout << "rInteger's address : " << &rInteger << endl;
	cout << "aRInteger's address : " << &aRInteger << endl;
	cout << "aRInteger_nonRefKeyword's address : " << &aRInteger_nonRefKeyword << endl;

	// 반대로 "런타임"에 타입이 추론되는 RTTI의 종류에는
	// dynamic_cast<>, typeId()

	return 0;
}