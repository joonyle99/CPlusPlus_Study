#include <iostream>
#include <string>

using namespace std;

int main()
{
	int number;
	std::string fullName;

	std::cout << "Enter a number: ";
	std::cin >> number;                   // 엔터로 입력 종료 후, '\n'가 입력 버퍼에 남아있음

	// std::cin.clear();
	std::cin.ignore();

	std::cout << "Enter your name: ";
	std::getline(cin, fullName);    // 남아있는 '\n' 때문에 fullName 변수에 값을 입력받기 전에 입력 종료

	std::cout << "Number: " << number << std::endl;
	std::cout << "Name: " << fullName << std::endl;












	return 0;
}