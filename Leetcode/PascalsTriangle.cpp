#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generateTriangle(int n){
    int dp[31][31];
    memset(dp, 0, sizeof dp);

    //setting first column and diagonal elements to "1"
    for(int i=0; i<n; i++){
        // first column
        dp[i][0]=1;

        // diagonal element 
        dp[i][i]=1;
    }

    for(int i=2;i<n;i++){
        for(int j=1;j<n;j++){
            // the current element is the sum of two numbers which are directly above it
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }

    vector<vector<int> > ans;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<i+1;j++){
            temp.push_back(dp[i][j]);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the number of rows"<<endl;
    cin>>n;
    
    cout<<"The Pascal's triangle containing "<<n<<"rows is : "<<endl;
    vector<vector<int> > ans=generateTriangle(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}