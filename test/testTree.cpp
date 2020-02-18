#include"utils.h"
#include"tree.h"
#include"lib_head.h"

int main(){
    string s={"[3,9,20,null,null,15,7]"};
    Codec c;
    TreeNode* root=c.deserialize(s);


    // 测试105题/106题
    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,20,15,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root_q106 = buildTree_q106(inorder,postorder);
    TreeNode* root_q105 = buildTree_q105(preorder,inorder);
    




    vector<vector<int>> res_103 = zigzagLevelOrder_q103(root);

    return 0;
}