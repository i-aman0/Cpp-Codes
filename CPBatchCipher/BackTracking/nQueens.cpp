#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<bool>> &board, int col, int row){
    int n = board.size();

    // whether we have reached the end of the board
    if(col >= n || row >= n){
        return false;
    }

    // queen cannot be in the same row
    // check if in the same column 
    for(int i = col; i >= 0; i--){
        if(board[i][col] == true){
            return false;
        }
    }

    // check left and right diagonal
    for(int i = 1; (col - i >=0) && (row - i >= 0); i++){
        if(board[row - i][col - i] || board[row - 1][col + 1]){
            return false;
        }
    }

    return true;
}

int noOfWays(vector<vector<bool>> &board, int row){
    // if reached the end of the board
    if(row == board.size()){
        return 1;
    }

    int ways = 0;

    // if not reached the end of the board
    // to har column ke liye same process
    for(int col = 0; col < board[0].size(); col++){
        if(isSafe(board, col, row)){
            board[row][col] = true; // place the queen here 
            ways += noOfWays(board, row + 1);
            board[row][col] = false;
        }
    }

    return ways;
}

int main()
{
    int n;
    cout << "Enter the size of board" << endl;
    cin >> n;
    vector<vector<bool>> board(n, vector<bool>(n, false));

    cout << "The number of possible ways to place queen on " << n << " X " << n << " board is : " << noOfWays(board, 0) << endl;

    return 0;
}