/*
##STL
4. From a collection of words, one word is missing. Find the missing value 
   given original  list/vector of words and modified one.
*/

#include <iostream>
#include <list>
#include <string>
#include <iterator>
int main()
{
    std::string str1, str2;
    std::list< std::string> list1;
    std::list< std::string> list2;

    list1.push_back("Dhoni");
    list1.push_back("Kalam");
    list1.push_back("Manekshaw");
    
    list2.push_back("Kalam");
    list2.push_back("Manekshaw");
    for(std::list<std::string>::iterator itr=list1.begin();itr!=list1.end();)
    {
        bool erase_it = false;
        for(std::list<std::string>::iterator it2 = list2.begin(); it2!=list2.end(); )
        {
            if(*itr == *it2)   
            {
                it2 = list2.erase(it2); 
                erase_it = true; 
                break;
            }
            else
            {
                ++it2; 
            }
        }

        if(erase_it)
            itr = list1.erase(itr);
        else
            ++itr;
    }

    std::cout<<"Missing word from duplicate list : ";
    for(std::list<std::string>::iterator itr = list1.begin(); itr!=list1.end(); ++itr)
        std::cout<<' '<<*itr<<std::endl;

    return 0;
}


