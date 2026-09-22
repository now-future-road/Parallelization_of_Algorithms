#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    
    TreeNode(int x) : val(x) {}
};

int getBinaryTreeDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + std::max(getBinaryTreeDepth(root->left), getBinaryTreeDepth(root->right));
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    std::cout << getBinaryTreeDepth(root) << std::endl;

    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}