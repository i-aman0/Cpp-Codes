#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; // number of test cases
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> wealth(n);
        long long totalWealth = 0;
        long long maxWealth = 0;

        // Input and calculate total wealth and find the max wealth
        for (int i = 0; i < n; i++) {
            cin >> wealth[i];
            totalWealth += wealth[i];
            maxWealth = max(maxWealth, wealth[i]);
        }

        // The minimum wealth required to avoid unhappiness for the majority
        long long requiredTotal = maxWealth * (n - 1);  // If the richest person gets more gold, this is the critical point

        // Check if the richest person already causes unhappiness

        cout << "The answer is : ";
        if (requiredTotal >= totalWealth) {
            cout << 0 << endl; // No need for more gold
        } else {
            // Calculate the minimum x (gold) needed for Robin Hood to appear
            long long x = (requiredTotal - totalWealth + n - 2) / (n - 1);
            cout << x << endl;
        }
    }

    return 0;
}
