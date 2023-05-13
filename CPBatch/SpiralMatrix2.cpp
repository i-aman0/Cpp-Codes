#include<iostream>
using namespace std;

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>> ans(n, vector<int> (n, 0));
    int startRow = 0;
    int startCol = 0;
    int endRow = n - 1;
    int endCol = n - 1;
    int num = 1;

    while(startRow <= endRow && startCol <= endCol){
        for(int i = startCol; i <= endCol; i++){
            ans[startRow][i] = num++;
        }
        startRow++;

        for(int i = startRow; i <= endRow; i++){
            ans[i][endCol] = num++;
        }
        endCol--;

        if(startRow <= endRow){
            for(int i = endCol; i >= startCol; i--) {
                ans[endRow][i] = num++;
            }
            endRow--;
        }

        if (startCol <= endCol){
            for(int i = endRow; i >= startRow; i--) {
                ans[i][startCol] = num++;
            }
            startCol++;
        }
    }

    return ans;
}


int main()
{
    int n = 3;
    vector<vector<int>> ans = generateMatrix(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}