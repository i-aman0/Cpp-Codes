#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

// https://cses.fi/problemset/task/1084

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

    // n applicants, m free apartments, k is the maximum allowed difference

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    for(int i = 0; i < n; i++){
        cin >> applicants[i];
    }

    vector<int> apartment(m);
    for(int i = 0; i < m; i++){
        cin >> apartment[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartment.begin(), apartment.end());

    
    
    return 0;
}