#include"utils.h"

int main(){
    string s={"[1,2,3,null,4]"};
    Codec c;
    TreeNode* root=c.deserialize(s);
    cout << root->val << " ";
    cout << root->left->val << " ";
    return 0;
}