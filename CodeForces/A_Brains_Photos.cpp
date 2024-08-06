#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

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

    int n, m;
    cin >> n >> m;

    vector<vector<char>> color(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char ch;
            cin >> ch;
            color[i][j] = ch;
        }
    }

    bool isBlack = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(color[i][j] == 'W' || color[i][j] == 'B' || color[i][j] == 'G'){
                continue;
            }
            else{
                isBlack = false;
                break;
            }
        }
    }

    if(isBlack){
        cout << "#Black&White" << endl;
    }
    else{
        cout << "#Color" << endl;
    }

    
    return 0;
}