/*
## STL
1. Write a function that takes collection of numbers and a target number. 
   It should  find two different elements in the array that, when added together will be equal to target
   value.Consider std::vector or std::list for input elements, 
   Return the indices of two elements as std::pair object.
   If no such pair, whose sum is not equal to target number , return the pair {-1,-1}
    
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

pair<int,int> Pair (vector<int> g1, int target){
    pair<int, int> P;
    for (auto i = g1.begin(); i != g1.end(); ++i){
	    for (auto j = i+1; j != g1.end(); ++j){
	        if(*i + *j == target){
	            auto it1 = find(g1.begin(), g1.end(), *i);
	            auto it2 = find(g1.begin(), g1.end(), *j);
	            int i1 = it1 - g1.begin();
	            int i2 = it2 - g1.begin();
	            
	            P.first=i1;
	            P.second=i2;
	            return P;
	            exit(1);
	        }
	    }
	}
	P.first=-1;
	P.second=-1;
	return P;
}

int main()
{
	vector<int> g1;
    pair<int, int> P;
    
	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Elements in the vector : ";
	for (auto i = g1.begin(); i != g1.end(); ++i){
		cout << *i << " ";}
		cout << endl;
		
	int target = 3;
	cout << "Target : " << target << endl;
	
	P = Pair(g1,target);
	cout << "Indicies : " << P.first << "," << P.second << endl;

	return 0;
}
