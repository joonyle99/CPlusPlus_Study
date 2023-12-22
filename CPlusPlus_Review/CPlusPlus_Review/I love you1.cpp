#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string s = "I Love You";

	/// 1. ' '를 기준으로 각각의 단어를 가져와서
	std::vector<std::string> strVec;

	int offset = 0;
	int count = 0;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
		{
			count = i - offset;
			strVec.push_back(s.substr(offset, count));
			offset = i + 1;
		}
		else if (i == s.length() - 1)
		{
			count = i - offset + 1;
			strVec.push_back(s.substr(offset, count));
			break;
		}
	}

	/// 2. 각각의 단어에서 문자 단위로 배열을 뒤집은 후
	for(int i=0; i<strVec.size(); ++i)
	{
		for(int j=0; j<strVec[i].length(); ++j)
		{
			std::swap(strVec[i][j], strVec[i][strVec[i].length() - 1 - j]);
		}
	}

	/// 3. 단어 단위로 뒤집는다.
	for (int i = 0; i < strVec.size() / 2; ++i)
	{
		std::swap(strVec[i], strVec[strVec.size() - 1 - i]);
	}

	// 출력
	for (const auto word : strVec)
		std::cout << word << " ";

	return 0;
}