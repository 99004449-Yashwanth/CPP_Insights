/*
## STL
    
3. Given the total distance travelled by a Vehicle at regular intervals 
   and value of interval, calculate average speed of the vehicle.
   e.g. [0, 0.1, 0.25, 0.45, 0.55, 0.7, 0.9, 1.0]
*/
   
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

float avg_speed (vector<float> g1){
    float sum=0;
    float avg=0;
    
    for (auto i = g1.begin(); i != g1.end(); ++i){
        sum = sum + *i ;
    }
    
    avg = sum/g1.size();
	return avg;
}

int main()
{
	vector<float> g1{0, 0.1, 0.25, 0.45, 0.55, 0.7, 0.9, 1.0};
    
    cout << "Average Speed : "<< avg_speed(g1) << endl;
    
	return 0;
}