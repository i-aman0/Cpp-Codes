#include<iostream>
using namespace std;

void isPresent(char ch){
    int n = 10;
    string str = "codeforces";
    for(int i = 0; i < n; i++){
        if(str[i] == ch){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main()
{
    int t;
    cin >> t;

    while(t){
        char ch;
        cin >> ch;
        isPresent(ch);
        t--;
    }
    return 0;
}