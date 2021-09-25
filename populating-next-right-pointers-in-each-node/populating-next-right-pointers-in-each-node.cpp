class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root; 
        while (head && head->left) {
            Node* node = head; 
            while (node) {
                node->left->next = node->right; 
                if (node->next) node->right->next = node->next->left; 
                node = node->next; 
            }
            head = head->left; 
        }
        return root; 
    }
};