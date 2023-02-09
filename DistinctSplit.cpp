#include<iostream>
#include<unordered_map>
using namespace std;

int maxSum(int n, string str){
    unordered_map<char, int> m;

    for(int i = 0; i < n; i++){
        m[str[i]]++;
    }

    
}

int main()
{
    int t;
    cin >> t;

    while(t){
        int n;
        cin >> n;
        string str;
        cin >> str;

        cout << maxSum(n, str) << endl;
        t--;
    }
    return 0;
}