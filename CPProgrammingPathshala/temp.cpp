#include <bits/stdc++.h>
// #include<iostream>
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

    int a;
    int b;

    cin >> a >> b;

    cout << a + b << endl;
    
    return 0;
}