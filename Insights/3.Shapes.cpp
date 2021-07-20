/*
##Insights

3. Write a function tcompute, which takes Shape pointer/reference, 
   but should able to call Traingle specific functionality like TypeOfTriangle, 
   isRightAngled along with common functions area, circumference. Hint:- dynamic_cast 
*/

#include<stdio.h>
#include<iostream>
#include<string>
#include <cmath>
using namespace std;
std::string type;
class shape
{
    private:
    int val1;
    int val2;
    int val3;
    public:
    shape():val1(0),val2(0),val3(0){}
    shape(int v1,int v2,int v3):val1(v1),val2(v2),val3(v3){}
    virtual std::string tcompute()
    {
        type ="Shape";
        return type;
    }
};
class triangle:public shape{
    private:
    int a;
    int b;
    int c;
    public:
    triangle():a(0),b(0),c(0){}
    triangle(int v1,int v2,int v3):a(v1),b(v2),c(v3){}
    std::string tcompute();
    
};
std::string triangle:: tcompute()
{
        float area = 0;
        float s=0;
        float circumference = 0;
        
        if(a==b && b==c && c==a)
        {
             type= "Equilateral";
             area = (0.43301270189*a*a);
        }
        else if(a==b || b==c || c==a){
            type= "Isoceles";
            if(a==b){
                area=0.5*(sqrt(((a*a)-(c*c))/4)*c);
            }
            if(a==c){
                area=0.5*(sqrt(((a*a)-(b*b))/4)*b);
            }
        }
        else
        {
            type= "Scalane";
            s=(a+b+c)/2;
            area = sqrt(s*(s-a)*(s-b)*(s-c));
        }
        
        
        circumference = (a+b+c)/3;
        cout << "Area : "<<area << " | Circumference : " << circumference << endl;
        return type;
    }
int main()
{
    shape *s= new triangle(5,4,3);
    triangle* t =dynamic_cast<triangle*>(s);
    if(t)
    {
        std::cout<<"The type of trianlge is : "<<s->tcompute();
    }
    else
    std::cout<<"Pointer not created!";
    return 0;
}