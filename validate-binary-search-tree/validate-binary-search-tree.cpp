class Solution {
public:
    
    struct TreeNode *prev = NULL;
    bool isValidBST(TreeNode* root) {
        
        if(root) {
            if(!isValidBST(root->left)) return false ; 
            
            if(prev != NULL && prev->val >= root->val) return false ;
            prev = root; 
            
            return isValidBST(root->right);
        }
        
        return true ;
    }
};