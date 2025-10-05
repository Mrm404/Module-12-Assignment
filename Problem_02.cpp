#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int range_sum_bst(TreeNode* root, int low, int high) {
    if (!root) return 0;  

    int sum = 0;
    
    if (root->val >= low && root->val <= high)
        sum += root->val;
    if (root->val > low)
        sum += range_sum_bst(root->left, low, high);
    if (root->val < high)
        sum += range_sum_bst(root->right, low, high);

    return sum;
}
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);
    int low = 7, high = 15;
    cout << "Range Sum between " << low << " and " << high << ": "
         << range_sum_bst(root, low, high) << endl;

    return 0;
}
/*
Time Complexity: O(n) in the worst case (unbalanced tree),
                 O(log n + m) on average for balanced BST where m is the number of nodes in range.
Space Complexity: O(h), where h is the height of the tree (O(log n) for balanced BST, O(n) for unbalanced).
*/
