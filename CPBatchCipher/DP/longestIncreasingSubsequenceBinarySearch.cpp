#include<iostream>
using namespace std;

// this method gives the length of the LIS only, may not give the exact subsequence

int main()
{
    vector<int> arr = {10,9,2,5,3,7,101,18};
    int n = arr.size();
    vector<int> lisArr;
    lisArr.push_back(arr[0]);

    for(int i = 1; i < n; i++){
        if(lisArr.back() < arr[i]){
            lisArr.push_back(arr[i]);
        }
        else{
            // finding the index of the number just greater than arr[i]
            // works similar to binary search
            int index = lower_bound(lisArr.begin(), lisArr.end(), arr[i]) - lisArr.begin();
            lisArr[index] = arr[i];
        }
    }

    cout << "The length of LIS is : " << lisArr.size() << endl;
    return 0;
}