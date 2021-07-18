/*
## STL
9. A MAC address will be in the form of 6 pair of hex digits (octets) separated 
   by colon. Given MAC address in string form, return vector/list with 6 
   integer values representing each pair/octet.
*/

#include<iostream>
#include<list>
#include <sstream>

using namespace std;

list<int> getlist(string MACaddr)
{
    stringstream s(MACaddr);
    string array[6];
    list<int> maclist;
    int value;
    for(int i=0;i<6;i++)
    {
        getline(s,array[i],':');
        stringstream ss;
        ss<<array[i];
        ss >> hex >> value;
        maclist.push_back(value);
    }
    return maclist;
}

int main(){
    string MACaddr="A1:23:9B:F8:1D:5C";
    list<int> answerlist = getlist(MACaddr);
    for(auto i:answerlist)
    {
        cout<<i<<endl;
    }
}