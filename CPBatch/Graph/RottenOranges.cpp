#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int rottenOranges(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int cntFresh = 0;

    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 2){
                visited[i][j] == 2;
            }
            else{
                visited[i][j] == 0;
            }
            if(grid[i][j] == 1){
                cntFresh++;
            }
        }
    }

    int time = 0;
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, 1, 0, -1}; 
    int cnt = 0;

    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        time = max(time, t);
        q.pop();

        for (int i = 0; i < 4; i++) {
            // neighbouring row and column
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            // check for valid cell and 
            // then for unvisited fresh orange
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                // push in queue with timer increased
                q.push({{nrow, ncol}, t + 1}); 
                // mark as rotten
                visited[nrow][ncol] = 2;
                cnt++;
            }
        }
    }

    if(cntFresh != cnt){
        return -1;
    }

    return time;
}

int main()
{
    
    return 0;
}