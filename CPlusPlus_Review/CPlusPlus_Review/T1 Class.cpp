#include <iostream>

using namespace std;

class Team
{
private:
	string teamName;

private:
	string topName;
	string jugName;
	string midName;
	string adName;
	string supName;

public:
	Team()
		: teamName("T1"),
		topName("zeus"), jugName("oner"), midName("faker"),
		adName("gumayusi"), supName("keria")
	{}
	~Team() = default;

public:
	void PrintTeamName() { cout << teamName << endl; }
	void PrintAllPlayerName()
	{
		cout << "Top : " << topName << endl;
		cout << "Jug : " << jugName << endl;
		cout << "Mid : " << midName << endl;
		cout << "Ad : " << adName << endl;
		cout << "Sup : " << supName << endl;
	}
};

int main()
{
	// 포인터에 값을 동적 할당
	Team* pTeam = new Team;
	cout << "Team : " << pTeam << endl;
	pTeam->PrintTeamName();
	pTeam->PrintAllPlayerName();

	// 메모리를 해제
	delete pTeam;
	pTeam = nullptr;
	cout << "Team : " << pTeam << endl;

	// 유효성 검사 (nullptr인지 확인)
	if (pTeam != nullptr)
		pTeam->PrintTeamName();

	// 해제된 메모리를 nullptr로
	pTeam = nullptr;
	cout << "Team : " << pTeam << endl;
	pTeam->PrintTeamName();

	return 0;
}