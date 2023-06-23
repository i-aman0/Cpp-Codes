#include <iostream>
#include <vector>
#include <cmath>
#include <ostream>
#include <list>
#include <map>
#include <algorithm>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <iterator>
#include <set>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <queue>
#include <chrono>
#include <deque>
#include <string>
#include <unordered_map>
#include<assert.h>
#include <unordered_set>

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

#define ll long long

using namespace std;



int main(){
    v();

    int n;
    cin >> n;

    if(n < 4){
        cout << "NO\n";
    }    
    else if(n % 2 == 0){
        cout << "YES\n";
        cout << "3 * 4 = 12\n";
        cout << "12 * 2 = 24\n";
        cout << "24 * 1 = 24\n";

        for(int i = 6; i <= n; i += 2){
            cout << i << " - " << i - 1 << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    }
    else{
        cout << "YES\n";
        cout << "5 * 4 = 20\n";
        cout << "20 + 3 = 23\n";
        cout << "23 + 2 = 25\n";
        cout << "25 - 1 = 24\n";

        for(int i = 7; i <= n; i += 2){
            cout << i << " - " << i - 1 << " = 1\n";
            cout << "24 * 1 = 24\n";
        }
    }
    return 0;
}