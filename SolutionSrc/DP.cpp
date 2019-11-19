#include "DP.h"
#include "lib_head.h"

int dpSolution::maxProfit_q121(vector<int>& prices){   
    //记录当前可以获得的最佳收益
    int maxProfit=-1;   
    int size = prices.size();
    if(size<2) return 0;
    //记录之前最小的股票价格
    int minStock = prices[0]>prices[1]?prices[1]:prices[0];
    for(int i=1;i<size;i++){
        maxProfit = std::max(maxProfit,prices[i]-minStock);
        minStock = minStock>prices[i]?prices[i]:minStock;
    }
    return maxProfit;
}


int dpSolution::longestPalindrome_q409(string s){

    #define _HASH

    #ifdef _SET
    std::set<char> myset;
    int result = 0;
    for(int i=0;i<s.size();i++){
        auto iter = myset.find(s[i]);
        if(iter==myset.end()){
            myset.insert(s[i]);
        }else{
            myset.erase(iter);
            result += 2;
        }
    }
    if(!myset.empty()){
        result += 1;
    }
    return result;
    #endif

    #ifdef _HASH
    std::unordered_map<char,int> myMap;
    for(char c : s ){
        myMap[c] += 1;
    }
    int result = 0;
    for(auto iter = myMap.begin();iter!=myMap.end();iter++){
        result += (iter->second%2==0)?iter->second:(iter->second-1);
    }
    if(result<s.size()) result += 1;
    return result;
    #endif
}