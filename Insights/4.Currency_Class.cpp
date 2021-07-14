/*	
	##INSIGHTS
	4. In Currency class, ensure constructors are only meant for initialization, Hint:- explicit
   Implement following user defined type conversions
   - Given total no.of paise, distribute as ruppees and paise, Hint:- operator=
   - Convert currency object as total no.of paise, Hint:- operator int
*/

#include <iostream>
using namespace std;

class Currency
{
private:
	int m_rupee;
	int m_paise;

public:
	Currency() : m_rupee(0), m_paise(0) {}

	Currency(int rupee, int paise) : m_rupee(rupee), m_paise(paise) {}

	//explicit Currency(int trupee, int tpaise):m_rupee(tpaise/100 + trupee), m_paise(tpaise%100){}

	explicit Currency(int tpaise) : m_rupee(tpaise / 100), m_paise(tpaise % 100) {}

	explicit Currency(const Currency &ref) : m_rupee(ref.m_rupee), m_paise(ref.m_paise) {}

	Currency &operator=(int tpaise)
	{
		m_rupee = tpaise / 100 + this->m_rupee;
		m_paise = tpaise % 100;
		return *this;
	}

	operator int()
	{
		return m_rupee * 100 + m_paise;
	}

	void display()
	{
		cout << "Paise to Rupee Paise : " << this->m_rupee << " Rupees " << this->m_paise << " Paise" << endl;
	}
};

int main()
{
	Currency c1;
	c1 = 333;
	c1.display();

	Currency c2(2, 105);
	int npaise;
	npaise = c2;
	cout << "Rupee Paise to Paise : " << npaise << " Paise" << endl;

	return 0;
}