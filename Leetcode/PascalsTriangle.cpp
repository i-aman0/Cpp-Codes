#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > generateTriangle(int n){
    int arr[30][30];

    // setting every element of the 2D array to '0'
    // the memset function copies a single character for a specified numebr of times to an object
    // here it copies '0' for sizeof number of times to the 2D array
    memset(arr, 0, sizeof arr);

    //setting first column and diagonal elements to "1"
    for(int i=0; i<n; i++){
        // first column
        arr[i][0]=1;

        // diagonal element 
        arr[i][i]=1;
    }

    for(int i=2;i<n;i++){
        for(int j=1;j<n;j++){
            // the current element is the sum of two numbers which are directly above it
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        }
    }

    vector<vector<int> > ans;
    for(int i=0;i<n;i++){

        // a vector for storing the elements present in a single row of the 2D array arr
        vector<int> temp;
        for(int j=0;j<i+1;j++){
            temp.push_back(arr[i][j]);
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