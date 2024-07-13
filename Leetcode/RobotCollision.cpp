#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

// https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2024-07-13

void v(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
}

using namespace std;

vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> idx(n);
        vector<int> ans;
        stack<int> st;

        for(int i = 0; i < n; i++){
            idx[i] = i;
        }

        // this line sorts the idx array based on the values of positions array
        // we need to do this so that the position entered first should be processed first 
        sort(idx.begin(), idx.end(), [&](int i, int j) {return positions[i] < positions[j]; });

        cout << "After sorting, the index array is : ";
        for(auto i : idx){
            cout << i << " ";
        }

        cout << endl;

        for(int i : idx){
            if(directions[i] == 'R'){
                st.push(i);
            }
            else{
                while(!st.empty() && healths[i]){
                    int top = st.top();
                    st.pop();

                    if(healths[top] > healths[i]){
                        healths[top]--;
                        healths[i] = 0;
                        st.push(top);
                    }
                    else if(healths[top] < healths[i]){
                        healths[i]--;
                        healths[top] = 0;
                    }
                    else{
                        healths[i] = 0;
                        healths[top] = 0;
                    }
                }
            }
        }

        for(auto health : healths){
            if(health){
                ans.push_back(health);
            }
        }

        return ans;
    }

int main(){
    //v();

    vector<int> positions = {5,4,3,2,1};
    vector<int> health = {2,17,9,15,10};
    string dir = "RRRRR";

    vector<int> result = survivedRobotsHealths(positions, health, dir);

    cout << "The health of survived robots is : ";
    for(auto res : result){
        cout << res << " ";
    }
    return 0;
}