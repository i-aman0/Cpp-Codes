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
        int a, b;
        cin >> a >> b;

        int sum = a + (2 * b);

        bool isPossible = false;

        if(sum % 2){
            isPossible = false;
        }
        else{
            int halfSum = sum / 2;
            for (int i = 0; i <= b; ++i) {
                int sumUsingTwos = i * 2;
                if (sumUsingTwos <= halfSum && halfSum - sumUsingTwos <= a) {
                    isPossible = true;
                }
            }
        }

        if(isPossible){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}