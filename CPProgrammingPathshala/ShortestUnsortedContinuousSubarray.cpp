#include<iostream>
#include<stack>
using namespace std;

int solve(vector<int> &arr){
    int n = arr.size();

    stack<int> pre;
    stack<int> post;

    

    int s = 0;
    int e = n - 1;

    for(int i = 0; i < n; i++){
        
    }
    return e - s + 1;
}

int main(){
    vector<int> arr = {2,6,4,8,10,9,15};

    cout << "The shortest length of unsorted array is : " << solve(arr) << endl;
}