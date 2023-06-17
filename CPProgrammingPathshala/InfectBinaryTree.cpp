#include<iostream>
#include<map>

using namespace std;


//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
private:
    int dfsHeight(TreeNode* root, map<TreeNode*, int> &heights){
        if(root == NULL) return 0;

        int h = max(dfsHeight(root -> left, heights), dfsHeight(root -> right, heights)) + 1;

        heights[root] = h;

        return h;
    }

    int dfsInfected(TreeNode* root, map<TreeNode*, int> &infected, int start){
        if(root == NULL) return -1;

        int h = max(dfsInfected(root -> left, infected, start), dfsInfected(root -> right, infected, start));

        if(h != -1){
            h++;
        }

        if(root -> val == start){
            h = 0;
        }

        infected[root] = h;
        return h;

    }

    void check(TreeNode* root, map<TreeNode*, int> &heights, map<TreeNode*, int> &infected, int &ans){
        if(root == NULL){
            return;
        }

        if(infected[root] != -1){
            if(root -> left == NULL){
                ans = max(ans, infected[root]);
            }
            else if(infected[root -> left] == -1){
                ans = max(ans, infected[root] + heights[root -> left]);
            }

            if(root -> right == NULL){
                ans = max(ans, infected[root]);
            }
            else if(infected[root -> right] == -1){
                ans = max(ans, infected[root] + heights[root -> right]);
            }
        }

        check(root -> left, heights, infected, ans);
        check(root -> right, heights, infected, ans);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, int> heights;
        map<TreeNode*, int> infected;

        dfsHeight(root, heights);
        dfsInfected(root, infected, start);

        int ans = 0;

        check(root, heights, infected, ans);

        return ans;

    }
};

int main(){
    
    return 0;
}