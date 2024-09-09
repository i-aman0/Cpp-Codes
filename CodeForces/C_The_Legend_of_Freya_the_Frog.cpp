#include <iostream>
#include <algorithm>

using namespace std;

// Function to compute minimum number of moves
int minMoves(int x, int y, int k) {
    // Calculate the minimum moves needed to cover x and y
    int movesX = (x + k - 1) / k;
    int movesY = (y + k - 1) / k;
    
    // Total moves needed is the maximum of moves required for x and y
    // plus the alternate direction constraint
    int maxMoves = max(movesX, movesY);
    return maxMoves + (maxMoves - 1);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        cout << "ans ";
        cout << minMoves(x, y, k) << endl;
    }

    return 0;
}
