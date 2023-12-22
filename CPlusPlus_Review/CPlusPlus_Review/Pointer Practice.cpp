#include <iostream>

// call by value
void TestN(int _n, int* _pN)
{
	printf("[TestN] %d\t %d\n", _n, *(_pN));

	_n++;
	// �� 1���� ++�� �߻�
	(*_pN)++;
}

void TestP(int* _p, int** _pP)
{
	printf("[TestP] %d\t %d\n", *(_p), **(_pP));

	// �� 2���� ++�� �߻�
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

	// call by value��, ����ȭ X
	printf("* n is %d\n", n);

	int* pN = &n;
	TestP(pN, &pN);

	// call by address��, ����ȭ O
	printf("** n is %d\n", n);

	std::cout << "============================================================" << std::endl;

	// �Ʒ� �ڵ��� �������� �����Դϱ�?

	int* p = nullptr;
	int** pp = nullptr; // p�� �����͸� ����Ű�� ������
	int m = 2022;

	// ���⿡�� p, pp�� �ּҸ� �־��־�� �Ѵ�.
	// �ֳ��ϸ� ������ p�� pp�� ��ȭ��Ű�� ���ؼ��� �ּҸ� �־ p, pp�� "����"�� �����ؾ� �ϱ� �����̴�.
	// ���� p, pp�� �ּҸ� �־����� ������, p, pp�� "���纻"�� �����ϰ� �ǰ�, �� ���纻�� *p = new int(1999);�� �ϰ� �Ǵ� ���̴�.
	// �׷��� �ȴٸ� �Լ����� ���� p, pp�� printf()�� �غ��Ƶ� nullptr�� ��µ� ���̴�.

	TestNew(&p, &pp, m);

	if (p != nullptr) printf("*p is %d\n", *p);
	if (pp != nullptr) printf("**pp is %d\n", **pp);

	printf("m is %d\n", m);


	return 0;
}