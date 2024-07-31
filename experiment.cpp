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

bool isPossible(string &a, string &b){
    int n = a.length();

    if(n != b.length()){
        return false;
    }

    int s = 0;

    for(int i = 0; i < n; i++){
        s ^= a[i] ^ b[i];
    }

    if(s == 0){
        return true;
    }

    return false;
}

int main(){
    //v();
    string a = "aba";
    string b = "baa";

    if(isPossible(a, b)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    cout << "String a is : " << a << endl;
    cout << "String b is : " << b << endl;

    
    return 0;
}