#include <iostream>

int main()
{
	// auto Ű����� "������ Ÿ��"�� Ÿ���� �߷еȴ�

	auto integer = 4;
	auto floating = 4.5f;
	auto doubling = 4.5;
	auto charr = 'c';

	int* pInteger = &integer;
	auto* aPInteger = pInteger;	// auto�� int Ÿ��
									// �����͸� ���޹������� auto*�� �̿��Ѵ� (auto ��ü�� int*�� ��)

	int& rInteger = integer;
	auto& aRInteger = rInteger;	// auto�� int Ÿ��
									// ������ ���޹������� auto&�� �̿��Ѵ� (������ ���޹��� �� ���� ������)

	auto aRInteger_nonRefKeyword = rInteger;	// auto&�� ������ ������ ���� ���۷����� ������� �ʰ� ���ο� �޸𸮿� �Ҵ�ȴ�

	using std::cout;
	using std::endl;

	cout << "integer's address : " << &integer << endl;
	cout << "rInteger's address : " << &rInteger << endl;
	cout << "aRInteger's address : " << &aRInteger << endl;
	cout << "aRInteger_nonRefKeyword's address : " << &aRInteger_nonRefKeyword << endl;

	// �ݴ�� "��Ÿ��"�� Ÿ���� �߷еǴ� RTTI�� ��������
	// dynamic_cast<>, typeId()

	return 0;
}