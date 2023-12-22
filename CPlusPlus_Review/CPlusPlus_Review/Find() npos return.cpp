#include <iostream>
#include <string>

using namespace std;

bool containsTripleSix(int num)
{
	// find()�� ������ std::string::npos�� ��ȯ
	return to_string(num).find("666") != string::npos;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// N��° ������ ���ϱ�
	int N; cin >> N;

	if (N > 10000 || N < 1)
		return -1;

	int count = 0;
	int num = 666;

	while (true)
	{
		// 666�� ���Ե� ���������� Ȯ��
		if (containsTripleSix(num))
		{
			count++;

			if (count == N)
			{
				cout << num << '\n';
				break;
			}
		}

		num++;
	}

	return 0;
}