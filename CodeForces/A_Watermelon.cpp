// #include <bits/stdc++.h>
#include<iostream>

#define ll long long
#define mod 1e9 + 7

using namespace std;

// https://codeforces.com/problemset/problem/4/A

// void v(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     srand((unsigned int)time(NULL));
// }

using namespace std;



int main(){
    //v();

    int w;
    cin >> w;

    if(w > 2 && w % 2 == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    
    return 0;
}