#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

// https://leetcode.com/problems/create-binary-tree-from-descriptions/?envType=daily-question&envId=2024-07-15

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

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int> parents, children;
        unordered_map<int, vector<pair<int, int>>> relation;

        for(auto &desc : descriptions){
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            parents.insert(parent);
            parents.insert(child);
            children.insert(child);

            relation[parent].push_back({child, isLeft});
        }

        for(auto it = parents.begin(); it != parents.end();){
            if(children.find(*it) != children.end()){
                it = parents.erase(it);
            }
            else{
                it++;
            }
        }

        TreeNode *root = new TreeNode(*parents.begin());

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *parent = q.front();
            q.pop();

            for(auto &info : relation[parent -> val]){
                int childVal = info.first;
                int isLeft = info.second;

                TreeNode *child = new TreeNode(childVal);
                q.push(child);

                if(isLeft){
                    parent -> left = child;
                }
                else{
                    parent -> right = child;
                }
            }
        }

        return root;
    }

    void inorder(TreeNode *root){
        if(root == NULL){
            return;
        }

        inorder(root -> left);
        cout << root -> val << " ";
        inorder(root -> right);
    }

int main(){
    //v();

    vector<vector<int>> desc = {{20,15,1}, {20,17,0}, {50,20,1}, {50,80,0}, {80,19,1}};

    TreeNode *root = createBinaryTree(desc);

    cout << "The inorder traversal is : ";
    inorder(root);

    return 0;
}