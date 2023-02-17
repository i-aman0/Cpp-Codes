#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

bool checkSquare(vector<int> &arr){
    int n = arr.size();

    for(int i = 0; i < n; i++){
        int a = sqrt(arr[i]);

        if(a*a != arr[i]){
            return false;
        }
    }

    return true;
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

        if(!checkSquare(arr)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        t--;
    }
    return 0;
}