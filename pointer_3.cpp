#include <iostream>
#include <vector>
#include <algorithm>

struct MTreeNode {
    int val;
    std::vector<MTreeNode*> children;
    
    MTreeNode(int x) : val(x) {}
};

int getMTreeDepth(MTreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int maxChildDepth = 0;
    for (MTreeNode* child : root->children) {
        maxChildDepth = std::max(maxChildDepth, getMTreeDepth(child));
    }

    return 1 + maxChildDepth;
}

int main() {
    MTreeNode* root = new MTreeNode(1);
    MTreeNode* child1 = new MTreeNode(2);
    MTreeNode* child2 = new MTreeNode(3);
    MTreeNode* grandchild = new MTreeNode(4);

    root->children.push_back(child1);
    root->children.push_back(child2);
    child1->children.push_back(grandchild);

    std::cout << getMTreeDepth(root) << std::endl;

    delete grandchild;
    delete child1;
    delete child2;
    delete root;

    return 0;
}