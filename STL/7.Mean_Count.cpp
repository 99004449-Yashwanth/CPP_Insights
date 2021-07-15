/*
## STL
   
7. In a given collection(list/vector) of elements, 
   count no.of elements smaller than their mean
   count no.of elements larger than their mean
   and return the absolute difference between both the counts
*/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int LowerArray(vector<int> &arr, int n)
{
    int countSmaller=0;
    int initial_sum = 0;
    for(int i=0; i<n; i++)
    {
        initial_sum += arr[i];
    }
    for(int i=0; i<n; i++){
        if (arr[i]<(initial_sum/n)){
            countSmaller++;
        }
    }
    return countSmaller;
}

int LargerArray(vector<int> &arr, int n)
{
    int countLarger = 0;
    int initial_sum = 0;
    for(int i=0; i<n; i++)
    {
        initial_sum += arr[i];
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]>(initial_sum/n))
        {
            countLarger++;
        }
    }
    return countLarger;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int a = LowerArray(arr, n);
    int b = LargerArray(arr, n);
    cout<<"Number of Elements Smaller mean : "<<a<<endl;
    cout<<"Number of Elements Larger mean : "<<b<<endl;
    int x = abs(a);
    int y = abs(b);
    cout<<"Absolute difference both count : "<<a-b<<endl;
}
