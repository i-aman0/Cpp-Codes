#include<iostream>
#include<vector>
using namespace std;

// given a string, find the length of maximum substring without repeating characters

// T.C. --> O(n^2)
//S.C. --> O(1)
int maxLength(string str){
    int result=0;
    int n=str.size();

    for(int i=0;i<n;i++){
        // a vector having characters of the string as indexes
        // basically the ASCII values of characters are the indices 
        // that's why size=256
        vector<bool> visited(255);
        for(int j=i; j<n;j++){

            // if the characters is already visited 
            // then corresponding to that index value true will be stored 
            // in such case break out of the loop
            if(visited[str[j]]==true){
                break;
            }   

            // else update the result and mark the character as visited
            else{
                result=max(result, j-i+1);
                visited[str[j]]=true;
            }
        }

        // slide the window forward by removing the first character of the previous window
        visited[str[i]]=false;
    }
    return result;
}

int main()
{
    string str="abcabcbb";
    cout<<"The length of maximum substring without repeating characters is : "<<maxLength(str)<<endl;
    return 0;
}