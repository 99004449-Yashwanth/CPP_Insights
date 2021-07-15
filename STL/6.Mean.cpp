/*
## STL
    
6. In a given collection(list/vector) of elements, 
   count no.of elements smaller than their mean
*/

#include<iostream>
#include<vector>
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

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Number less than mean : " << LowerArray(arr, n)<<endl;
}
