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
        // strlen(str) + 1 개 만큼 char 공간 확보
        this->m_str = new char[strlen(str) + 1];

        // strlen(str) + 1 개의 문자 복사
        strcpy_s(m_str, strlen(str) + 1, str);
    }

public:
    // 두 문자열을 합친 문자열을 반환
    String operator + (const String& string)
    {
        String str(this->m_str);
        strcat_s(str.m_str, strlen(str.m_str) + strlen(string.m_str) + 2, string.m_str);
        return str;
    }
    // 해당 문자열에 뒤에 오는 문자열을 합쳐서 반환
    String& operator += (const String& string)
    {
        strcat_s(this->m_str, strlen(this->m_str) + strlen(string.m_str) + 2, string.m_str);
        return *this;
    }
    // 해당 문자열에 뒤에 오는 문자열을 넣어서 반환
    String& operator = (const String& string)
    {
        delete[] this->m_str;
        this->m_str = nullptr;
        this->m_str = new char[strlen(string.m_str) + 1];
        strcpy_s(this->m_str, strlen(string.m_str) + 1, string.m_str);
        return *this;
    }
    // 두 문자열 객체가 같은 문자열인지 확인
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
    // 프렌드 키워드 + << 연산자 오버로딩
    // 멤버 함수가 아니다, 일반 함수 형태로 정의한 것
    friend ostream& operator << (ostream& os, const String& string)
    {
        os << string.m_str;
        return os;
    }

private:
    char* m_str;
    size_t m_size;
};

//생성자
//복사 생성자
//복사 대입 연산자
//연산자 함수 + == <<

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