
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode *left, *right;
    
    TreeNode(int data) {
        this->data = data;
        left = right = NULL;
    }
};

void morrisInorderTraversal(TreeNode *root) {

    TreeNode *curr = root;

    while(curr) {

        if(curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else {
            TreeNode *pre = curr->left;
            while(pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }
            if(pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            }
            else {
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }

    }

}

int main() {

    //creating tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(5);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);

    //doing morris inorder traversal
    cout << "Inorder: ";
    morrisInorderTraversal(root);
    cout << endl;

}