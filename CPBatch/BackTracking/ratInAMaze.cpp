#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>> &maze, int a, int b){
    if(a >= maze.size() || b >= maze[0].size() || maze[a][b] == 0){
        return false;
    }

    return true;
}

bool isSol(vector<vector<int>> &maze, int a, int b){
    return (a == maze.size() - 1 && b == maze[0].size() - 1);
}

int noOfWays(vector<vector<int>> &maze, int a, int b){
    if(!isSafe(maze, a, b)){
        return 0;
    }

    if(isSol(maze, a, b)){
        return 1;
    }

    int moveDown = noOfWays(maze, a + 1, b);
    int moveRight = noOfWays(maze, a, b + 1);

    return moveDown + moveRight;
}

int main()
{
    
    return 0;
}