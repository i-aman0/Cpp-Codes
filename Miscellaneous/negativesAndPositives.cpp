#include<iostream>
#include<vector>
using namespace std;

int maxSum(vector<int> arr, int n){
    int sum = 0;

    for(int i = 0; i < n - 1; i++){
        

        if(arr[i] < 0 && arr[i + 1] < 0){
            arr[i] = -arr[i];
            arr[i + 1] = -arr[i + 1];
            i++;
        }

        if(arr[i] < 0 && arr[i + 1] > 0){
            if(abs(arr[i]) > arr[i + 1]){
                arr[i] = -arr[i];
                arr[i + 1] = -arr[i + 1]; 
            }
        }

        if(arr[i] > 0 && arr[i + 1] < 0){
            if(arr[i] < abs(arr[i + 1])){
                arr[i] = -arr[i];
                arr[i + 1] = -arr[i + 1];
            }
        }
        
    }

    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
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