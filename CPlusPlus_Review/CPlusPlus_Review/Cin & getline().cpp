#include <iostream>
#include <string>

using namespace std;

int main()
{
	int number;
	std::string fullName;

	std::cout << "Enter a number: ";
	std::cin >> number;                   // ���ͷ� �Է� ���� ��, '\n'�� �Է� ���ۿ� ��������

	// std::cin.clear();
	std::cin.ignore();

	std::cout << "Enter your name: ";
	std::getline(cin, fullName);    // �����ִ� '\n' ������ fullName ������ ���� �Է¹ޱ� ���� �Է� ����

	std::cout << "Number: " << number << std::endl;
	std::cout << "Name: " << fullName << std::endl;












	return 0;
}