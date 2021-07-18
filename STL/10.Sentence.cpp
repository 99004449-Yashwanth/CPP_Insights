/*
##STL
10. Given a sentence in string form, return a map of pairs , 
    where in each pair - word as key and length of the word as value.
    Double the length if word already present in the map (duplicate)
*/    

#include <iostream>
#include <map>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <sstream>
void tokensize(std::string const &str, const char delim,std::map<std::string,int> &word)
{
    std::stringstream ss(str);
    std::string s;
    while (std::getline(ss, s, delim)) 
    {
        word.insert(std::pair<std::string,int>(s,s.length()));
    }
}
int main()
{
    std::string str="Engineering the change";
    const char delim = ' ';
    std::map<std::string, int> mapOfWordCount;
    tokensize(str,delim,mapOfWordCount);
    for( std::map<std::string, int>::iterator it= mapOfWordCount.begin();it != mapOfWordCount.end();it++)
    {
        std::cout<<it->first << ":"<<it->second<<std::endl;
    }
return 0;
}
