#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> digits(n);

        pair<int, int> mini = {INT_MAX, -1}; // stores {minValue, index}

        for(int i = 0; i < n; i++){
            cin >> digits[i];
        }

        for(int i = 0; i < n; i++){
            if(digits[i] < mini.first){
                mini.first = digits[i];
                mini.second = i;
            }
        }

        digits[mini.second]++;

        int prod = 1;

        for(int i = 0; i < n; i++){
            prod *= digits[i];
        }

        cout << prod << endl;

    }

    return 0;
}