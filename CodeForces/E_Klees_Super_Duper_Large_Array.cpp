#include <iostream>
#include <cmath>

using namespace std;

// Function to compute the minimum possible value of x
long long minValue(long long n, long long k) {
    // Total sum of the array
    long long totalSum = (n * (2 * k + (n - 1))) / 2;

    // The minimum value of x, initialized to a large number
    long long minX = LLONG_MAX;

    // Try both floor(n/2) and ceil(n/2) to find the minimal x
    long long i1 = n / 2;
    long long i2 = (n + 1) / 2;

    // Calculate sum for i1
    long long sumFirst_i1 = (i1 * (2 * k + (i1 - 1))) / 2;
    long long x1 = abs(2 * sumFirst_i1 - totalSum);
    minX = min(minX, x1);

    // Calculate sum for i2 (only if i2 is different from i1)
    if (i2 != i1) {
        long long sumFirst_i2 = (i2 * (2 * k + (i2 - 1))) / 2;
        long long x2 = abs(2 * sumFirst_i2 - totalSum);
        minX = min(minX, x2);
    }

    return minX;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << "ans : ";
        cout << minValue(n, k) << endl;
    }

    return 0;
}
