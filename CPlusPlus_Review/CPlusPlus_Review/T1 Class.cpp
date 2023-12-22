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
	// �����Ϳ� ���� ���� �Ҵ�
	Team* pTeam = new Team;
	cout << "Team : " << pTeam << endl;
	pTeam->PrintTeamName();
	pTeam->PrintAllPlayerName();

	// �޸𸮸� ����
	delete pTeam;
	pTeam = nullptr;
	cout << "Team : " << pTeam << endl;

	// ��ȿ�� �˻� (nullptr���� Ȯ��)
	if (pTeam != nullptr)
		pTeam->PrintTeamName();

	// ������ �޸𸮸� nullptr��
	pTeam = nullptr;
	cout << "Team : " << pTeam << endl;
	pTeam->PrintTeamName();

	return 0;
}