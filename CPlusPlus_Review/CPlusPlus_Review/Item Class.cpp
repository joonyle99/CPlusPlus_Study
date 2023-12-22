// ReSharper disable CppClangTidyClangDiagnosticInvalidSourceEncoding
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// �۷ι� ����
int g_id = 0;

enum class ItemGrade
{
	C = 0,
	B,
	A,
	S,



	NONE
};

enum class ItemType
{
	���� = 0,
	��,
	����,
	�Ź�,


	NONE
};

string TypeToString(ItemType type)
{
	string str;

	if (type == ItemType::����)
		str = "����";
	else if (type == ItemType::��)
		str = "��";
	else if (type == ItemType::����)
		str = "����";
	else if (type == ItemType::�Ź�)
		str = "�Ź�";
	else
		str = "";

	return str;
}

ItemType StringToType(string str)
{
	ItemType type;

	if (str == "����")
		type = ItemType::����;
	else if (str == "��")
		type = ItemType::��;
	else if (str == "����")
		type = ItemType::����;
	else if (str == "�Ź�")
		type = ItemType::�Ź�;
	else
		type = ItemType::NONE;

	return type;
}

char GradeToChar(ItemGrade grade)
{
	char c;

	if (grade == ItemGrade::C)
		c = 'C';
	else if (grade == ItemGrade::B)
		c = 'B';
	else if (grade == ItemGrade::A)
		c = 'A';
	else if (grade == ItemGrade::S)
		c = 'S';
	else
		c = ' ';

	return c;
}

ItemGrade CharToGrade(char c)
{
	ItemGrade grade;

	if (c == 'C')
		grade = ItemGrade::C;
	else if (c == 'B')
		grade = ItemGrade::B;
	else if (c == 'A')
		grade = ItemGrade::A;
	else if (c == 'S')
		grade = ItemGrade::S;
	else
		grade = ItemGrade::NONE;

	return grade;
}

class Item
{
private:
	int m_id;
	string m_name;
	ItemType m_type;
	int m_level;
	ItemGrade m_grade;


public:
	Item(int id, string name, ItemType type, int level, ItemGrade grade)
	{
		m_id = id;
		m_name = name;
		m_type = type;
		m_level = level;
		m_grade = grade;
	}
	~Item();

public:
	int GetId() const { return m_id; }
	string GetName() const { return m_name; }
	ItemType GetType() const { return m_type; }
	int GetLevel() const { return m_level; }
	ItemGrade GetGrade() const { return m_grade; }

public:
	void SetId(int id) { m_id = id; }
	void SetName(string name) { m_name = name; }
	void SetType(ItemType type) { m_type = type; }
	void SetLevel(int level) { m_level = level; }
	void SetGrade(ItemGrade grade) { m_grade = grade; }

public:
	void LevelUp()
	{
		m_level++;
	}
	void Show()
	{
		cout << m_id << ". ";
		cout << m_name << ", ";
		cout << TypeToString(m_type) << ", ";
		cout << m_level << ", ";
		cout << "\'" << GradeToChar(m_grade) << "\' " << endl;
	}

};

class Weapon : public Item
{
private:
	int attack;

public:
	Weapon(int id, string name, ItemType type, int level, ItemGrade grade)
		: Item(id, name, type, level, grade)
	{
		attack = 100;
	}
	~Weapon()
	{}
};

class Armor : public Item
{
private:
	int armor;

public:
	Armor(int id, string name, ItemType type, int level, ItemGrade grade)
		: Item(id, name, type, level, grade)
	{
		armor = 200;
	}
	~Armor()
	{}
};

class Ring : public Item
{
private:
	int intelligence;

public:
	Ring(int id, string name, ItemType type, int level, ItemGrade grade)
		: Item(id, name, type, level, grade)
	{
		intelligence = 70;
	}
	~Ring()
	{}
};

class Shose : public Item
{
private:
	int speed;

public:
	Shose(int id, string name, ItemType type, int level, ItemGrade grade)
		: Item(id, name, type, level, grade)
	{
		speed = 35;
	}
	~Shose()
	{}
};

class Inventory
{
private:
	vector<Item*> itemList;

private:
	string name;
	string type;
	int level;
	char grade;

public:
	void CreateItem()
	{
		cout << "===============================================" << endl;
		cout << "�������� �Է��ϼ��� (�̸�, ����, ����, ���)" << endl;
		cout << "===============================================" << endl;

		cin >> name;
		cin >> type;
		cin >> level;
		cin >> grade;

		Item* newItem = nullptr;

		switch(StringToType(type))
		{
		case ItemType::����:
			newItem = new Weapon(g_id + 1, name, StringToType(type), level, CharToGrade(grade));
			break;
		case ItemType::��:
			newItem = new Armor(g_id + 1, name, StringToType(type), level, CharToGrade(grade));
			break;
		case ItemType::����:
			newItem = new Ring(g_id + 1, name, StringToType(type), level, CharToGrade(grade));
			break;
		case ItemType::�Ź�:
			newItem = new Shose(g_id + 1, name, StringToType(type), level, CharToGrade(grade));
			break;
		default:
			newItem = new Item(g_id + 1, name, StringToType(type), level, CharToGrade(grade));
			break;
		}

		itemList.push_back(newItem);

		++g_id;
	}
	void DeleteItem()
	{
		cout << "=======================================" << endl;
		cout << "������ �������� ��ȣ�� �Է��ϼ���" << endl;
		cout << "=======================================" << endl;

		int id; cin >> id;

		itemList.erase(itemList.begin() + id - 1);

		// TODO : index�� �ڵ����� ��������� id�� ������� �ʱ� ������ ���� ����ִ� �۾�
		for (int i = id - 1; i < itemList.size(); i++)
		{
			itemList[i]->SetId(itemList[i]->GetId() - 1);
		}

		--g_id;
	}
	void LevelUp()
	{
		cout << "==========================================================" << endl;
		cout << "������ �� �������� ��ȣ�� �Է��ϼ��� (�ִ� 10����)" << endl;
		cout << "==========================================================" << endl;

		int id; cin >> id;

		// ������ 10���� ������ ������ ����
		if (itemList[id - 1]->GetLevel() >= 10)
			return;

		itemList[id - 1]->LevelUp();
	}
	void Compound()
	{
		cout << "=====================================================================" << endl;
		cout << "�ռ����� ����� �ø����� �ϴ� �������� 2�� �Է��ϼ��� ex 2 3" << endl;
		cout << "=====================================================================" << endl;

		int id1; cin >> id1;
		int id2; cin >> id2;

		Item* item1 = itemList[id1 - 1];
		Item* item2 = itemList[id2 - 1];

		if (item1->GetGrade() == ItemGrade::S)
			return;

		if (item1->GetGrade() != item2->GetGrade())
			return;

#pragma region DeleteItems

		// ���� 2���� ��Ḧ ����

		// 1��° ��� ����
		itemList.erase(itemList.begin() + id1 - 1);

		// TODO : index�� �ڵ����� ��������� id�� ������� �ʱ� ������ ���� ����ִ� �۾�
		for (int i = id1 - 1; i < itemList.size(); i++)
		{
			itemList[i]->SetId(itemList[i]->GetId() - 1);
		}

		--g_id;

		// 2��° ��� ����
		itemList.erase(itemList.begin() + id2 - 2);

		// TODO : index�� �ڵ����� ��������� id�� ������� �ʱ� ������ ���� ����ִ� �۾�
		for (int i = id2 - 2; i < itemList.size(); i++)
		{
			itemList[i]->SetId(itemList[i]->GetId() - 1);
		}

		--g_id;

#pragma endregion

		Item* newItem = nullptr;

		switch (StringToType(type))
		{
		case ItemType::����:
			newItem = new Weapon(g_id + 1, item1->GetName(), item1->GetType(), 1, static_cast<ItemGrade>(static_cast<int>(item1->GetGrade()) + 1));
			break;
		case ItemType::��:
			newItem = new Armor(g_id + 1, item1->GetName(), item1->GetType(), 1, static_cast<ItemGrade>(static_cast<int>(item1->GetGrade()) + 1));
			break;
		case ItemType::����:
			newItem = new Ring(g_id + 1, item1->GetName(), item1->GetType(), 1, static_cast<ItemGrade>(static_cast<int>(item1->GetGrade()) + 1));
			break;
		case ItemType::�Ź�:
			newItem = new Shose(g_id + 1, item1->GetName(), item1->GetType(), 1, static_cast<ItemGrade>(static_cast<int>(item1->GetGrade()) + 1));
			break;
		default:
			newItem = new Item(g_id + 1, item1->GetName(), item1->GetType(), 1, static_cast<ItemGrade>(static_cast<int>(item1->GetGrade()) + 1));
			break;
		}

		itemList.push_back(newItem);

		++g_id;
	}
	void ShowInventory()
	{
		cout << "������ ��� : " << endl;
		for(auto item : itemList)
			item->Show();
	}
};


int main()
{
	Inventory inventory;

	while(true)
	{
		cout << "=========================================================================" << endl;
		cout << "1. ������ �߰�  2, ����  3. ������  4. �ռ�  5. ��Ϻ��� (0. ������)" << endl;
		cout << "=========================================================================" << endl;
		int choice; cin >> choice;

		switch (choice)
		{
		case 1:
			inventory.CreateItem();
			break;
		case 2:
			inventory.DeleteItem();
			break;
		case 3:
			inventory.LevelUp();
			break;
		case 4:
			inventory.Compound();
			break;
		case 5:
			inventory.ShowInventory();
			break;
		case 0:
			cout << "���α׷��� �����մϴ�" << endl;
			return -1;
		}
	}


	return 0;
}