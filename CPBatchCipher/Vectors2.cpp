#include<iostream>
#include<vector>
using namespace std;

// when the vector is full, the capacity of vector doubles so that the elements remain consecutive

void display(vector<vector<vector<int>> > &vecna){
    for(auto layer1: vecna){
        for(auto layer2: layer1){
            for(auto element: layer2){
                cout << element << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr;

    // reserving the capacity to 2 
    // it will keep on increasing as we push more elements
    arr.reserve(2);

    // for(int i = 0; i < 100; i++){
    //     arr.push_back(i);
    //     cout << i << " : " << arr.size() << " " << arr.capacity() << endl;
    // }

    // we can visualise a 2d vector as a 1d vector of a 1d vector
    // and 3d vector as a 1d vector of 2d vector
    vector<int> linear = {1, 2, 3, 4, 5};
    vector< vector<int> > twoD = {linear, linear, linear, linear, linear};
    vector< vector<vector<int>> > threeD = {twoD, twoD, twoD, twoD, twoD};

    display(threeD);
    return 0;
}