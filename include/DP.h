#ifndef __DP
#define __DP

#include"utils.h"
#include"lib_head.h"

using std::vector;
using std::string;


class dpSolution{
    public:
        int maxProfit_q121(vector<int>& prices);
        int longestPalindrome_q409(string s); 
        bool divisorGame_1025(int N);
        vector<int> sortArrayByParity_q905(vector<int>& A);
        int numDecodings_q91(string s);
};



#endif