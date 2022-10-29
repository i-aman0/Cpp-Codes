#include<iostream>
using namespace std;

// 1st approach by calculating the reverse first

// void reverseString(string &str, int i, int j){
//     // base case
//     if(i>j){
//         return;
//     }

//     swap(str[i], str[j]);
//     i++;
//     j--;

//     reverseString(str, i, j);
// }

// bool isPalindrome(string str){
//     string temp=str;
//     reverseString(temp, 0, temp.length()-1);
//     if(temp==str){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

bool isPalindrome(string str, int i, int j){
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        return isPalindrome(str, i+1, j-1);
    }
}

int main()
{
    string str="aabbaaa";
    
    bool ans=isPalindrome(str, 0, str.length()-1);

    if(ans){
        cout<<"The string is palindrome"<<endl;
    }
    else{
        cout<<"The string is not palindrome"<<endl;
    }
    return 0;
}