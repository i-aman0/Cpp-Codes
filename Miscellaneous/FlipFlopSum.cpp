#include<iostream>
#include<vector>
using namespace std;

int maxSum(vector<int> &arr, int n){
    int sum = 0;
    int originalSum = 0;

    bool isTwo = false;

    for(int i = 0; i < n; i++){
        if(arr[i] == -1 && arr[i + 1] == -1){
            isTwo = true;
            break;
        }
    }

    for(int i = 0; i < n - 1; i++){
        sum += arr[i];
    }

    if(sum == n){
        return n - 4;
    }

    if(sum + 2 == n){
        return sum;
    }

    if(isTwo){
        return sum + 4;
    }

    return sum ;
}


int main()
{
    int t;
    cin >> t;

    while(t){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        cout << maxSum(arr, n) << endl;
        t--;
    }
    return 0;
}