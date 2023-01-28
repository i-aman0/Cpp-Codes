#include<iostream>
#include<vector>
using namespace std;

void calculate(int n, string red, string blue){
    vector<int> redArr;
    vector<int> blueArr;

    for (int j = 0; j < n; ++j) {
        redArr.push_back((int)red[j]);
    }

    for (int j = 0; j < n; ++j) {
        blueArr.push_back((int)blue[j]);
    }

    int redSum = 0;
    int blueSum = 0;

    for (int j = 0; j < n; ++j) {
        if (redArr[j]>blueArr[j]){
            redSum++;
        } 
        else if (blueArr[j]>redArr[j]){
            blueSum++;
        }
    }

    if (redSum>blueSum){
        cout<<"RED\n";
    } 
    else if (blueSum>redSum){
        cout<<"BLUE\n";
    } 
    else{
        cout<<"EQUAL\n";
    }
}

int main()
{
    int t;
    cin >> t;

    while(t){
        int n;
        string red, blue;
        cin >> n;
        cin >> red;
        cin >> blue;
        calculate(n, red, blue);
        t--;
    }
    return 0;
}