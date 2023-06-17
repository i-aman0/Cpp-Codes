#include<iostream>

using namespace std;

// https://codeforces.com/problemset/problem/1814/A

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        if(n % 2 == 0){
            cout << "Yes" << endl;
        }
        else{
            if(k % 2 == 0){
                cout << "No" << endl;
            }
            else{
                if(n >= k){
                    cout << "Yes" << endl;
                }
                else{
                    cout << "No" << endl;
                }
            }
        }
    }
}