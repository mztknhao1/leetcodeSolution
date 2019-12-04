#include"utils.h"
#include"tree.h"

int main(){
    string s={"[1,2,5,3,4,null,6]"};
    Codec c;
    TreeNode* root=c.deserialize(s);
    TreeSolution t;
    t.flatten_q114(root);
    cout << root->val;
    return 0;
}