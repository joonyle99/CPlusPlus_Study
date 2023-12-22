#include <iostream>

using namespace std;

class String
{
public:
    String() : m_str(nullptr), m_size(0) {}
    ~String() {}
    String(const char* str)
        : m_str(nullptr), m_size(0)
    {
        // strlen(str) + 1 �� ��ŭ char ���� Ȯ��
        this->m_str = new char[strlen(str) + 1];

        // strlen(str) + 1 ���� ���� ����
        strcpy_s(m_str, strlen(str) + 1, str);
    }

public:
    // �� ���ڿ��� ��ģ ���ڿ��� ��ȯ
    String operator + (const String& string)
    {
        String str(this->m_str);
        strcat_s(str.m_str, strlen(str.m_str) + strlen(string.m_str) + 2, string.m_str);
        return str;
    }
    // �ش� ���ڿ��� �ڿ� ���� ���ڿ��� ���ļ� ��ȯ
    String& operator += (const String& string)
    {
        strcat_s(this->m_str, strlen(this->m_str) + strlen(string.m_str) + 2, string.m_str);
        return *this;
    }
    // �ش� ���ڿ��� �ڿ� ���� ���ڿ��� �־ ��ȯ
    String& operator = (const String& string)
    {
        delete[] this->m_str;
        this->m_str = nullptr;
        this->m_str = new char[strlen(string.m_str) + 1];
        strcpy_s(this->m_str, strlen(string.m_str) + 1, string.m_str);
        return *this;
    }
    // �� ���ڿ� ��ü�� ���� ���ڿ����� Ȯ��
    bool operator == (const String& string)
    {
        if (strlen(this->m_str) != strlen(string.m_str))
            return false;

        for (size_t i = 0; i < strlen(this->m_str); ++i)
        {
            if (this->m_str[i] != string.m_str[i])
                return false;
        }

        return true;
    }

private:
    // ������ Ű���� + << ������ �����ε�
    // ��� �Լ��� �ƴϴ�, �Ϲ� �Լ� ���·� ������ ��
    friend ostream& operator << (ostream& os, const String& string)
    {
        os << string.m_str;
        return os;
    }

private:
    char* m_str;
    size_t m_size;
};

//������
//���� ������
//���� ���� ������
//������ �Լ� + == <<

int main(void)
{
    String s1 = "abc";
    String s2 = "def";

    String s3 = s1 + s2;

    String s4 = ""; s4 += s3;

    cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;

    cout << boolalpha;
    cout << (s1 == s4) << endl;

    s2 = s3;
    cout << s2 << endl;

	return 0;
}