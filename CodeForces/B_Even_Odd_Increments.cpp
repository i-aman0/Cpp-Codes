#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

void v(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
}

using namespace std;



int main(){
    // v();

    ll t;
    cin >> t;

    while(t--){
        ll n, q;
        cin >> n >> q;

        vector<ll> arr(n);

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        ll initialSum = 0;
        ll even = 0;
        ll odd = 0;

        for(ll i = 0; i < n; i++){
            ll num = arr[i];
            initialSum += num;
            if(num % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
        }        

        while(q--){
            ll type, val;
            cin >> type >> val;

            if(type == 0){
                initialSum += even * val;
                if(val % 2 != 0){
                    odd += even;
                    even = 0;
                }
            }
            else if(type == 1){
                initialSum += odd * val;

                if(val % 2 != 0){
                    even += odd;
                    odd = 0;
                }
                
            }

            cout << initialSum << "\n";
        }
    }
    
    return 0;
}