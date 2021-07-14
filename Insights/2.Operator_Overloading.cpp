// Copyright[2021]<Yashwanth>
/*
## Insights
2. Implement following operator overloading on Box class.
   ```
   MyString s1("abcd");
   MyString s2("xyz");
   s3 = s1 + s2;  // 
   s4 = s1 * 3;   // s4 will be "abcdabcdabcd", like in python
   s3 += "hello"; // s3 should be "abcdxyzhello"
   s2 *= 5;       // s2 should be "xyzxyzxyzxyzxyz"
   s5 = s1 * 2 + "hello"  // s5 should be "abcdabcdhello"
*/

#include <iostream>
#include <cstring>

using namespace std;

class Mystring
{
private:
    char *m_str;
    int m_len;

public:
    Mystring() : m_str(NULL)
    {
    }
    Mystring(const char *s)
    {
        if (s == NULL)
        {
            m_str = NULL;
            m_len = 0;
        }
        else
        {
            m_len = strlen(s);
            m_str = new char[m_len];
            for (int i = 0; i < m_len; i++)
                m_str[i] = s[i];
            m_str[m_len] = '\0';
        }
    }
    Mystring(const Mystring &ref)
    {
        int m_len = ref.m_len;
        if (ref.m_str)
        {
            m_str = new char[m_len + 1];
            for (int i = 0; i < m_len; i++)
                m_str[i] = ref.m_str[i];
            m_str[m_len] = '\0';
        }
        else
            m_str = NULL;
    }
    void print()
    {
        cout << this->m_str << endl;
    }

    Mystring operator+(const Mystring &ref)
    {
        int l = this->m_len + ref.m_len;
        char *temp = new char[l];
        for (int i = 0; i < this->m_len; i++)
            temp[i] = this->m_str[i];
        for (int i = 0; i < ref.m_len; i++)
            temp[this->m_len + i] = ref.m_str[i];
        temp[l] = '\0';
        Mystring s3(temp);
        delete[] temp;
        return s3;
    }

    Mystring operator*(int val)
    {
        int l =  (this->m_len)*val;
    char *temp = new char[l];
    int i=0;
    for(int j=0;j<val;j++)
       { for(int k=0 ;i<l,k<this->m_len;i++,k++)
          temp[i] = this->m_str[k];}
    temp[l]='\0';
    delete[] this->m_str;
    this->m_str = new char[l];
    for (int i = 0; i < l; i++)
        this->m_str[i] = temp[i];
    this->m_len = l;
    delete[] temp;
    return *this;
    }

    Mystring operator+=(const char* s)
    {
        int l = this->m_len + strlen(s);
        char *temp = new char[l + 1];
    for (int i = 0; i < this->m_len; i++)
        temp[i] = this->m_str[i];
    for (int i = 0; i < strlen(s); i++)
        temp[this->m_len + i] = s[i];
    temp[l] = '\0';
    delete[] this->m_str;
    this->m_str = new char[l];
    for (int i = 0; i < l; i++)
        this->m_str[i] = temp[i];
    this->m_len = l;
    delete[] temp;
    return *this;
    }

    Mystring operator*=(int val)
    {
        int l =  (this->m_len)*val;
    char *temp = new char[l];
    int i=0;
    for(int j=0;j<val;j++)
       { for(int k=0 ;i<l,k<this->m_len;i++,k++)
          temp[i] = this->m_str[k];}
    temp[l]='\0';
    delete[] this->m_str;
    this->m_str = new char[l];
    for (int i = 0; i < l; i++)
        this->m_str[i] = temp[i];
        delete[] this->m_str;
    this->m_str = new char[l];
    for (int i = 0; i < l; i++)
        this->m_str[i] = temp[i];
    this->m_len = l;
    delete[] temp;
    return *this;
    this->m_len = l;
    delete[] temp;
    return *this;
    }
};

int main()
{
    Mystring s1("abcd");

    Mystring s2("xyz");

    s1.print();
    s2.print();

    Mystring s3 = s1 + s2;
    cout << "s1+s2 : " ;
    s3.print();

    Mystring s4 = s1 * 3;
    cout << "s1*3 : " ;
    s4.print();

    s3 += "hello";
    cout << "s3+=hello : " ;
    s3.print();

    s2 *= 5;
    cout << "s2*=5 : " ;
    s2.print();

    Mystring s5 = (s1 * 2) + "hello";
    cout << "s5=s1*2+hello : " ;
    s5.print();


    
    //Mystring s3 = s1+s2;
}
