#include <iostream>
using namespace std;

// https://www.codechef.com/problems/BURGERS2?tab=statement
// make the equation 
// let we purchase p premium burgers then normal burgers = n - p
// solve the equation and the find value of p (n - p)x + py <= r
// p = (r - n * x) / (y - x)

int main() {
    int t;
    cin >> t;
    
    while(t--){
        int x, y, r, n;
        cin >> x >> y >> n >> r;
        
        if(x * n > r){
            cout << -1 << endl;
        }
        else{
            int numP = (r - n * x) / (y - x);
            numP = min(numP, n);
            cout << n - numP << " " << numP << endl;
        }
        
    }
    
	return 0;
}
// x -> normal burger
// y -> premium burger
// r -> amount
// n -> total burgers