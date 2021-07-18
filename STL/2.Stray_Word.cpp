/*
##STL
2. In a given collection of words, all elements are equal except the one.
   Write a code to find the odd man out (Stray word)
*/   

#include <iostream>
#include <list>
#include <bits/stdc++.h>
using namespace std;

string find_Odd_Word(list<string> words)
{
    int n = sizeof(words);
    list<string> uniqueWords = words;
    uniqueWords.sort();
    uniqueWords.unique();
    int c = count(words.begin(),words.end(),uniqueWords.front());
    int d = count(words.begin(),words.end(),uniqueWords.back());
    if(c==1)
    {
        return uniqueWords.front();
    }
    else
    {
        return uniqueWords.back();
    } 
}

int main()
{
  list<string> words{"Hi", "Hi", "Hi", "Hi", "Team"};
  cout<<find_Odd_Word(words)<<endl;
}