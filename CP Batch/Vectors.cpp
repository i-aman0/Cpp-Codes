#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &arr){
    int n = arr.size();

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    // the element here is by value 
    // i.e. if we change the value of element, the original vector will not be changed 
    // for(auto element : arr){
    //     cout << element << " ";
    // }
    cout<<endl;
    
}

int main()
{
    // vector<int> a = {1, 2, 3, 4};
    vector<int> a(10, 42);

    a.push_back(34);
    display(a);

    // creating a 2D vector and assigning every element to 1
    vector< vector<int> > matrix (10, vector<int> (10, 1));

    // for(auto col : matrix){
    //     for(auto element : col){
    //         cout << element << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < matrix.size(); i++){
        for(int j= 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }

    
    return 0;
}