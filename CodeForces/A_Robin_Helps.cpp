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
        int n, k;
        cin >> n >> k;

        // vector<int> arr(n, 0);
        int input;

        int currCount = 0;
        int given = 0;

        for(int i = 0; i < n; i++){
            cin >> input;

            if(input >= k){
                currCount += input;
            }
            else if(input == 0 && currCount > 0){
                given++;
                currCount--;
            }
        }

        cout << given << endl;
    }

    return 0;
}