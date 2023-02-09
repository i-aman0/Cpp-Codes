#include<iostream>
using namespace std;

void solve(string str, int n){
    int i = 0;
    int j = n - 1;

    while(i <= j){
        if(str[i] == str[j]){
            cout << j - i + 1 << endl;
            return;
        }
        i++;
        j--;
    }
    cout << 0 << endl;
}

int main()
{
    int t;
    cin >> t;

    while(t){
        int n;
        cin >> n;
        string str;
        cin >> str;
        solve(str, n);
        t--;
    }
    return 0;
}