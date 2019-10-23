#include"Solution.h"
#include <iostream>
#include<sstream>

using std::cout;
using std::endl;
using std::string;

void printVector(vector<int>& nums);

void printMatrix(vector<vector<int>>& matrix);

void printList(ListNode* l1);

class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root);
	/*Upperlevel*/
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data);		
};