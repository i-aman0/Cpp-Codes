#include <bits/stdc++.h>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define mod 1e9 + 7

using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }

        cout << sum << endl;
    }
    return 0;
}