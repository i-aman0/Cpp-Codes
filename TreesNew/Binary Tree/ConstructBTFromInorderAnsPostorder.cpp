#include<iostream>
#include<vector>
#include<map>
using namespace std;

class TreeNode{
    public: 
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this -> data = data;
        this -> left  = NULL;
        this -> right = NULL;
    }
};

TreeNode* solve(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> &m){
    if(is > ie || ps > pe){
        return NULL;
    }

    TreeNode* root = new TreeNode(postorder[pe]);
    int inRoot = m[postorder[pe]];
    int numsLeft = inRoot - is;

    root -> left = solve(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, m);
    root -> right = solve(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, m);

    return root;
}

TreeNode* createTree(vector<int> &inorder, vector<int> &postorder){
    int iSize = inorder.size();
    int pSize = postorder.size();

    if(iSize != pSize){
        return NULL;
    }

    map<int, int> m;
    for(int i = 0; i < iSize; i++){
        m[inorder[i]] = i;
    }

    return solve(inorder, 0, iSize - 1, postorder, 0, pSize - 1, m);
}

int main()
{
    
    return 0;
}