#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;  // number of test cases
    cin >> t;
    
    while (t--) {
        int n;  // length of the array
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        // Step 1: Find the maximum value in the array
        int max_element = *max_element(a.begin(), a.end());
        
        // Step 2: Count how many elements can be chosen (non-adjacent selection)
        int count_red = 0;
        for (int i = 0; i < n; i += 2) {
            count_red++;
        }
        
        // Step 3: Output the score (maximum element + number of red elements)
        int score = max_element + count_red;
        cout << score << endl;
    }
    
    return 0;
}
