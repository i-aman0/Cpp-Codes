#include<iostream>
using namespace std;

void reverseString(string &str, int i, int j){
    // base case
    if(i>j){
        return;
    }

    swap(str[i], str[j]);
    i++;
    j--;

    reverseString(str, i, j);
}

bool isPalindrome(string str){
    string temp=str;
    reverseString(temp, 0, temp.length()-1);
    if(temp==str){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string str="aabaa";
    
    bool ans=isPalindrome(str);

    if(ans){
        cout<<"The string is palindrome"<<endl;
    }
    else{
        cout<<"The string is not palindrome"<<endl;
    }
    return 0;
}