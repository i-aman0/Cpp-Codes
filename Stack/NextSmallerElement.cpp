#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// to find the next smaller element, we start traversal from the end of the array
// the last element will have no smaller element after it so store -1 corresponding to it
// see the top element if it is smaller than the current element, then it is the answer 
// store that answer ans push the current element in the stack 
// if the top element is not smaller than the current element, then keep on popping till top element is smaller than the current (while loop) 
// when we exit the loop, means that the top element will be smaller than the current (and that will be the answer)
// bcoz we exit the loop as soon as the top element becomes smaller than the current element

vector<int> findNextSmaller(vector<int> &arr){
    int size=arr.size();

    vector<int> ans(size);

    stack<int> s;

    // store -1 in the stack in starting for the last element 
    s.push(-1);

    for(int i=size-1; i>=0; i--){
        int curr=arr[i];

        while(s.top() >= curr){
            s.pop();
        }

        // top element is the answer
        ans[i]=s.top();

        s.push(curr);
    }
    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);

    vector<int> ans=findNextSmaller(arr);

    for(int i=0;i<ans.size();i++){
        cout<<arr[i]<<"\t"<<ans[i]<<endl;
    }
    return 0;
}