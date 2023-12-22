#include <iostream>

// call by value
void TestN(int _n, int* _pN)
{
	printf("[TestN] %d\t %d\n", _n, *(_pN));

	_n++;
	// 총 1번의 ++이 발생
	(*_pN)++;
}

void TestP(int* _p, int** _pP)
{
	printf("[TestP] %d\t %d\n", *(_p), **(_pP));

	// 총 2번의 ++이 발생
	(*_p)++;
	(**_pP)++;
}

void TestNew(int** p, int*** pp, int& r)
{
	*p = new int(1999);
	*pp = &(*p);
	r = **p;
}

int main()
{
	int n = 2021;
	TestN(n, &n);

	// call by value로, 값변화 X
	printf("* n is %d\n", n);

	int* pN = &n;
	TestP(pN, &pN);

	// call by address로, 값변화 O
	printf("** n is %d\n", n);

	std::cout << "============================================================" << std::endl;

	// 아래 코드의 문제점은 무엇입니까?

	int* p = nullptr;
	int** pp = nullptr; // p의 포인터를 가리키는 포인터
	int m = 2022;

	// 여기에서 p, pp의 주소를 넣어주어야 한다.
	// 왜냐하면 실제로 p와 pp를 변화시키기 위해서는 주소를 넣어서 p, pp의 "원본"에 접근해야 하기 때문이다.
	// 만약 p, pp의 주소를 넣어주지 않으면, p, pp의 "복사본"에 접근하게 되고, 그 복사본에 *p = new int(1999);를 하게 되는 것이다.
	// 그렇게 된다면 함수에서 나와 p, pp를 printf()를 해보아도 nullptr이 출력될 것이다.

	TestNew(&p, &pp, m);

	if (p != nullptr) printf("*p is %d\n", *p);
	if (pp != nullptr) printf("**pp is %d\n", **pp);

	printf("m is %d\n", m);


	return 0;
}