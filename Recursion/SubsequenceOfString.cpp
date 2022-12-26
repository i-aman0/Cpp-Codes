
// given a string return all the possible subsequences of the string

#include<iostream>
#include<vector>
using namespace std;

void solve(string str, string output, int index, vector<string> &ans){
    // base case
    if(index >= str.length()){
        ans.push_back(output);
        return;
    }

    // exclude the selected element
    solve(str, output, index+1, ans);

    // include the selected element
    char element=str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);    
}

vector<string> subsequence(string str){
    vector<string> ans;
    string output;
    int index=0;

    solve(str, output, index, ans);
    return ans;
}

int main()
{
    string str="abc";

    vector<string> ans=subsequence(str);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}