#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, vector<string>& v, vector<vector<int>>& dist) {
	return i >= 0 && j >=0 && i < v.size() && j < v[0].size() 
	&& v[i][j] != '#' && dist[i][j] == -1;
}

bool isValid(int i, int j, vector<string>& v, vector<vector<pair<int, char>>>& dist) {
	return i >= 0 && j >=0 && i < v.size() && j < v[0].size() 
	&& v[i][j] != '#' && dist[i][j].first == -1;
}

vector<vector<int>> calculateMonsterDistance(vector<string>& v) {
	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<pair<int, int> > q;
	for (int i = 0; i< v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 'M') {
				dist[i][j] = 0;
				q.push({i,j});
			}
		}
	}
	
	vector<pair<int, int> > directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
	while (!q.size()){
		pair<int, int> p = q.front();
		q.pop();
		for (auto it: directions) {
			int x = p.first + it.first;
			int y = p.second + it.second;
			if (isValid(x, y, v, dist)) {
				dist[x][y] = dist[p.first][p.second] + 1;
				q.push({x, y});
			}
		}
	}
	
	return dist;
}

vector<vector<pair<int, char>>> calculateCharacterDistance(vector<string> & v) {
	vector<vector<pair<int, char>>> dist(n, vector<pair<int, char>> (m, {-1, '$'}));
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == 'A') {
				dist[i][j] = {0, '.'};
				q.push({i,j});
			}
		}
	}
	
	vector<pair<pair<int, int>, char> > directions = {{{0, 1}, 'R'}, {{1, 0}, 'D'}, {{-1, 0}, 'U'}, {{0, -1}, 'L'}};
	while (!q.size()){
		pair<int, int> p = q.front();
		q.pop();
		for (auto it: directions) {
			int x = p.first + it.first.first;
			int y = p.second + it.first.second;
			if (isValid(x, y, v, dist)) {
				dist[x][y].first = dist[p.first][p.second].first + 1;
				dist[x][y].second = it.second;
				q.push({x, y});
			}
		}
	}
	
	return dist;
	
}

bool isValidExit(int x, int y, vector<int>& v) {
	return (x == 0 || x == v.size() - 1  || y == 0 || y == v[0].size() - 1) && v[x][y] == '.';
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v(n, "");
	for (int i = 0; i< n; i++) {
		cin >> v[i];
	}
	
	vector<vector<int>> monsterDist = calculateMonsterDistance(v);
	vector<vector<pair<int, char>>> charDist = calculateCharacterDistance(v);
	stack<char> st;
	for (int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			if (isValidExit(i,j, v)) {
				if (monsterDist[i][j] > charDist[i][j].first) {
					cout << "YES\n";
					cout << charDist[i][j].first << endl;
					while (charDist[i][j].second != '.') {
						st.push(charDist[i][j].second);
						// change i,j
					}
					break;
				}
			}
		}
	}
	cout << "No\n";
	return 0;
}