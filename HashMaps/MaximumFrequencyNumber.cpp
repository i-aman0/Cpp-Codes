// given an array of integers, return the number having the highest frequency. 
// If two numbers have same frequency, then return the number which comes first i.e. has lower index. 

#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

int maxNumber(vector<int> &arr){
    int s=arr.size();

    unordered_map<int, int> count;

    int maxFreq=0;
    int maxAns;

    for(int i=0; i<s; i++){
        count[arr[i]]++;
        maxFreq=max(maxFreq, count[arr[i]]);
    }

    for(int i=0; i<s; i++){
        if(maxFreq==count[arr[i]]){
            maxAns=arr[i];
            break;
        }
    }

    return maxAns;
}

int main()
{
    vector<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(2);

    int max=maxNumber(arr);

    cout<<"The number having highest frequency is : "<<max<<endl;

    return 0;
}