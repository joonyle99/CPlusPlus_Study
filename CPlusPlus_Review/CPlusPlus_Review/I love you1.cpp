#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string s = "I Love You";

	/// 1. ' '�� �������� ������ �ܾ �����ͼ�
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

	/// 2. ������ �ܾ�� ���� ������ �迭�� ������ ��
	for(int i=0; i<strVec.size(); ++i)
	{
		for(int j=0; j<strVec[i].length(); ++j)
		{
			std::swap(strVec[i][j], strVec[i][strVec[i].length() - 1 - j]);
		}
	}

	/// 3. �ܾ� ������ �����´�.
	for (int i = 0; i < strVec.size() / 2; ++i)
	{
		std::swap(strVec[i], strVec[strVec.size() - 1 - i]);
	}

	// ���
	for (const auto word : strVec)
		std::cout << word << " ";

	return 0;
}