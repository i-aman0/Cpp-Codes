#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getOrder(char ch) {
    return ch - 'a';
}

char getChar(int order) {
    return 'a' + order;
}

int main() {
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    if (s1.length() != s2.length()) {
        cout << "Error: Strings have different lengths." << endl;
        return 0;
    }

    int operations = 0;
    string result = "";

    for (size_t i = 0; i < s1.length(); i++) {
        int order_s1 = getOrder(s1[i]);
        int order_s2 = getOrder(s2[i]);

        cout << order_s1 << endl;
        cout << order_s2 << endl;

        int diff = abs(order_s1 - order_s2);
        if (diff <= 13) {
            operations += diff;
        } else {
            operations += order_s1 + order_s2 + 1 - 25;
        }
    }
    
    cout << "Number of operations: " << operations << endl;

    return 0;
}
