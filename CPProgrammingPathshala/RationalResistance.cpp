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

// void v(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     srand((unsigned int)time(NULL));
// }

#define ll long long

using namespace std;

void solve(ll a, ll b, ll &count){
    if(a == 0 || b == 0){
        return;
    }
    count += floor(a / b);
    a = a % b;
    solve(b, a, count);
}

int main(){
    // v();

    ll a, b;
    cin >> a >> b;

    ll count = 0;

    solve(a, b, count);

    cout << count << endl;
    return 0;
}