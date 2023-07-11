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
    v();

    string a, b; // a.length <= b.length
    cin >> a >> b;

    int res = 0;

    for(int i = 0; i < b.length() - a.length() + 1; i++){
        int t = 0;
        for(int j = i; j < i + a.length(); j++){
            t += abs((b[j] - '0') - (a[j - i] - '0'));
        }
        res += t;
    }

    cout << res;

    
    return 0;
}

// unsigned long decimal = bitset<32>(tmp).to_ulong();   binary string to number