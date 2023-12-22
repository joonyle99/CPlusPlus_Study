#include <iostream>
#include <string>

using namespace std;

bool containsTripleSix(int num)
{
	// find()는 없으면 std::string::npos를 반환
	return to_string(num).find("666") != string::npos;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// N번째 종말수 구하기
	int N; cin >> N;

	if (N > 10000 || N < 1)
		return -1;

	int count = 0;
	int num = 666;

	while (true)
	{
		// 666이 포함된 종말수인지 확인
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