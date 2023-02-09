#include<iostream>
using namespace std;

void isPasses(string str, int n){
    int x = 0;
    int y = 0;

    for(int i = 0; i < n; i++){
        char ch = str[i];

        if(ch == 'L'){
            x--;
        }

        if(ch == 'R'){
            x++;
        }

        if(ch == 'U'){
            y++;
        }

        if(ch == 'D'){
            y--;
        }
        
        if(x == 1 && y == 1){
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
        int n;
        cin >> n;
        string str;
        cin >> str;
        isPasses(str, n);
        t--;
    }
    return 0;
}