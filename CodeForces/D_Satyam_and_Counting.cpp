#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Point {
    int x, y;
};

int countRightTriangles(vector<Point>& points) {
    int n = points.size();
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    map<int, int> yIndices;
    for (int i = 0; i < n; i++) {
        if (points[i].y == 0) {
            yIndices[points[i].x] = i;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (points[i].y > 0) {
            auto leftIter = yIndices.lower_bound(points[i].x);
            auto rightIter = yIndices.upper_bound(points[i].x);

            if (leftIter != yIndices.end() && rightIter != yIndices.begin()) {
                int leftIndex = leftIter->second;
                int rightIndex = prev(rightIter)->second;

                int leftDist = abs(points[i].x - points[leftIndex].x);
                int rightDist = abs(points[i].x - points[rightIndex].x);

                if (leftDist == rightDist) {
                    count++;
                    cout << "Found a right triangle: (" << points[i].x << ", " << points[i].y << "), (" << points[leftIndex].x << ", " << points[leftIndex].y << "), (" << points[rightIndex].x << ", " << points[rightIndex].y << ")" << endl;
                }
            }
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Point> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].x >> points[i].y;
        }
cout << "Ans : ";
        cout << countRightTriangles(points) << endl;
    }

    return 0;
}