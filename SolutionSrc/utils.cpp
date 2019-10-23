#include"Solution.h"
#include"utils.h"
#include "dataStruct.h"

using std::cout;
using std::endl;

void printVector(vector<int>& nums){
    int n = nums.size();
    for(int i=0; i<n ; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>>& matrix){
    int rows = matrix.size();
    for(int i=0;i<rows;i++){
        printVector(matrix[i]);
    }
}

void printList(ListNode* l1){
    ListNode* tmp = l1;
    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

//序列化
string Codec::serialize(TreeNode* root){
    using std::to_string;
    if(root==nullptr) return "";

    string res;
    res += '[';
    //试试使用广度优先搜索算法
    std::queue<TreeNode*>* q = new std::queue<TreeNode*>;
    TreeNode* currentNode;
    q->push(root);
    while(!q->empty()){
        if(q->front() == nullptr) res += "null";
        else{
            res += std::to_string(q->front()->val);
            q->push(q->front()->left);
            q->push(q->front()->right);
        }
        q->pop();
        res.push_back(',');
    }

    while(1){
        char c = res.back();
        if(c==',' || c=='n' || c=='u' || c=='l'){
            res.pop_back();
        }
        else
        {
            break;
        }   
    }
    res.push_back(']');
	return res;    
}

TreeNode* Codec::deserialize(string data){
    if (data == "")return nullptr;
	//删除左右2个'['  ']'
	data.pop_back();
	data.erase(data.begin());

	std::stringstream ss(data);

	vector<string>temp;//temp 中储存的是 val 和 null 

	string init;
	while (getline(ss, init, ','))temp.push_back(init);//过滤 ','

	vector<TreeNode*>Upperlevel;//存储的是上一层的节点

	int i = 0;
	TreeNode* root = new struct TreeNode(atoi(temp[i++].data()));
	Upperlevel.push_back(root);

	while (i < temp.size()) {
		vector<TreeNode*>second;//存储下一层的节点

		for (auto& vi : Upperlevel) {//每个节点都需要考虑左右子节点,分类考虑就行了
			if (i < temp.size() && temp[i] == "null")++i;
			else if (i < temp.size()) {
				vi->left = new struct TreeNode(atoi(temp[i++].data()));
				second.push_back(vi->left);
			}
			if (i < temp.size() && temp[i] == "null") ++i;
			else if (i < temp.size()) {
				vi->right = new struct TreeNode(atoi(temp[i++].data()));
				second.push_back(vi->right);
			}
		}
		Upperlevel = second;
	}
	return root;
}

