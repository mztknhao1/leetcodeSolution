#include"utils.h"
#include"tree.h"

int main(){
    string s={"[3,5,1,6,2,0,8,null,null,7,4]"};
    Codec c;
    TreeNode* root=c.deserialize(s);
    TreeSolution t;
    // t.flatten_q114(root);
    // cout << root->val;
    TreeNode p(5);
    TreeNode q(1);
    std::stack<TreeNode*> result = t.findPath_q236(root,5);
    TreeNode* m = t.lowestCommonAncestor_q236(root,&p,&q);
    return 0;
}