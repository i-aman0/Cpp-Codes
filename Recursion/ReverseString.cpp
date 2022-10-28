#include<iostream>
using namespace std;

void solve(string& str, int i, int j){
    if(i>j){
        return;
    }
    swap(str[i], str[j]);
    i++;
    j--;

    solve(str, i, j);
}

void reverseString(string &str){
    int size=str.length();
    solve(str, 0, size-1);
}

int main()
{
    string str="macbook";

    reverseString(str);

    cout<<"The reversed string is : "<<str<<endl;

    return 0;
}