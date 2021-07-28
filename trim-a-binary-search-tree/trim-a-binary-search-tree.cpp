class Solution 
{
    public: TreeNode* trimBST(TreeNode *root, int L, int R) 
    {
        // if root is null its obvious that we need to return null
        if (root == NULL)
        {
            return NULL;
        }
        
        // if root value itself is equal to lowest value range, then complete left side of tree can be discarded. 
        if (root->val == L)
        {
            root->left = NULL;
            root->right = trimBST(root->right, L, R);
            return root;
        }
        
        // if root value itself is equal to highest value range, then complete left side of tree can be discarded.
        if (root->val == R)
        {
            root->right = NULL;
            root->left = trimBST(root->left, L, R);
            return root;
        }
        
        // if lowest and highest value both are greater than root then we know value we need remains at the right side of the tree. So trim right side. 
        if (root->val < L && root->val < R)
        {
            return trimBST(root->right, L, R);
        }
        
        // if lowest and highest value both are less than root then we know value we need remains at the left side of the tree. So trim left side. 
        if (root->val > L && root->val > R)
        {
            return trimBST(root->left, L, R);
        }
        
        // if all these conditions fail then we are sure that it is between left and right side of tree. So trim both 
        
        root->right = trimBST(root->right, L, R);
        root->left = trimBST(root->left, L, R);
        
        return root;

    }
};