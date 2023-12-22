#include <iostream>
#include <vector>

using namespace std;

class CMyData
{
public:
	int m_nData;
	int m_array[50];

public:
	// 인자 있는 생성자
	CMyData(int nParam)
		: m_nData(nParam)
		, m_array{}
	{}
	// 소멸자
	~CMyData() {}

public:
	/// 산술 연산자
	// 이항 연산자
	// () 안의 ref가 피연산자
	CMyData operator + (const CMyData& ref) const
	{
		return CMyData(this->m_nData + ref.m_nData);
	}
	CMyData operator - (const CMyData& ref) const
	{
		return CMyData(this->m_nData - ref.m_nData);
	}
	CMyData operator * (const CMyData& ref) const
	{
		return CMyData(this->m_nData * ref.m_nData);
	}
	CMyData operator % (const CMyData& ref) const
	{
		return CMyData(this->m_nData % ref.m_nData);
	}

	/// 증감 연산자
	CMyData& operator ++ () // c = ++a;
	{
		++this->m_nData;
		return *this;
	}
	CMyData operator ++ (int) // c = a++;
		// int는 피연산자를 식별하기 위함
		// a++에서 a가 피연산자
	{
		// this 객체의 data는 증가하지만, temp 객체의 data는 증가하지 않음
		CMyData temp(this->m_nData);
		++this->m_nData;
		return temp;
	}
	CMyData& operator -- ()
	{
		--this->m_nData;
		return *this;
	}
	CMyData operator -- (int)
	{
		CMyData temp(this->m_nData);
		--this->m_nData;
		return temp;
	}

	/// 비교 연산자
	bool operator < (const CMyData& ref) const
	{
		return this->m_nData < ref.m_nData;
	}
	bool operator > (const CMyData& ref) const
	{
		return this->m_nData > ref.m_nData;
	}
	bool operator <= (const CMyData& ref) const
	{
		return this->m_nData <= ref.m_nData;
	}
	bool operator >= (const CMyData& ref) const
	{
		return this->m_nData >= ref.m_nData;
	}
	bool operator == (const CMyData& ref) const
	{
		return this->m_nData == ref.m_nData;
	}
	bool operator != (const CMyData& ref) const
	{
		return this->m_nData != ref.m_nData;
	}

	/// 부호 연산자
	CMyData operator + ()
		// 단항연산자 + (부호 연산자로 사용)
		// () 안에 피연산자가 없음
	{
		return CMyData(+this->m_nData);
	}
	CMyData operator - ()
	{
		return CMyData(-this->m_nData);
	}

	/// 출력 연산자
	// friend 키워드 사용
	friend ostream& operator << (ostream& os, const CMyData& data)
	{
		os << data.m_nData;
		return os;
	}

	/// 배열 연산자
	int operator [] (int nIndex) const
	{
		return this->m_array[nIndex];
	}

	/// 함수 연산자
	CMyData operator () (const CMyData& data1, const CMyData& data2) const
	{
		return CMyData(data1.m_nData + data2.m_nData);
	}

	/// 포인터 연산자
	CMyData& operator * ()
	{
		return *this;
	}
	CMyData* operator -> ()
	{
		return this;
	}
};

int main()
{
	CMyData a(1); // a = 1
	CMyData b(2); // b = 2

	CMyData c = a + b; // c = 1 + 2
	cout << c << endl; // 3

	c = +a;			   // c = +1 (부호 연산자)
	cout << c << endl; // +1

	c = ++a;		   // c = ++1 = 2 (전위 증가 연산자 & 단항 연산자)
	cout << c << endl; // 2

	c = a++;		   // c = 2++ = 2 (후위 증가 연산자 & 단항 연산자)
	cout << c << endl; // 2
	cout << a << endl; // 3

	cout << boolalpha;
	cout << (a > b) << endl; // True

	//--------------------------------------------------------------------------------//
	cout << "//--------------------------------------------------------------------------------//" << endl;

	CMyData d = a - b;
	cout << d << endl; // 3 - 2

	d = a * b;
	cout << d << endl; // 3 * 2

	d = a % b;
	cout << d << endl; // 3 % 2

	cout << (a < b) << endl;	// False
	cout << (a > b) << endl;	// True
	cout << (a <= b) << endl;	// False
	cout << (a >= b) << endl;	// True
	cout << (a == b) << endl;	// False
	cout << (a != b) << endl;	// True

	cout << -a << endl; // -3
	cout << +a << endl; // +3

	cout << a[5] << endl; // 0

	cout << a(12, 54) << endl; // 12 + 54의 객체를 만듬

	cout << (*a).m_nData << endl;	 // 3 (this 객체)
	cout << a->m_nData << endl;		 // 3 (this 객체 포인터)

	return 0;
}