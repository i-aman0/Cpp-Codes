#include<iostream>
#include<vector>
using namespace std;

void solve(string digit, string output, int index, string mapping[], vector<string> &ans){
    if(index >= digit.length()){
        ans.push_back(output);
        return;
    }

    int number=digit[index]-'0';
    string val=mapping[number];

    for(int i=0; i<val.length(); i++){
        output.push_back(val[i]);
        solve(digit, output, index+1, mapping, ans);
        output.pop_back();
    }
}

vector<string> letterCombination(string digits){
    vector<string> ans;
    if(digits.length()==0){
        return ans;
    }

    string output;
    int index=0;

    string mapping[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, output, index, mapping, ans);
    return ans;
}

int main()
{
    string str="23";

    vector<string> ans=letterCombination(str);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}