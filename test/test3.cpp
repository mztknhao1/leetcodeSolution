/*
 * @Author: your name
 * @Date: 2019-12-08 13:14:45
 * @LastEditTime: 2020-04-05 08:21:35
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcodeSolution/test/test3.cpp
 */
#include"Solution.h"
#include"utils.h"
#include"LFU.h"

using std::cout;
using std::endl;

int main(){
    // 测试LFUCache
    LFUCache *LFUc = new LFUCache(3);
    LFUc->put(1,1);
    int rsLFU = LFUc->get(2);

    std::cout << "-----" << std::endl;


    Solution s;
    std::string test="aab";
    int n = s.lengthOfLongestSubstring_q3(test);
    cout << n <<endl;
    return 0;
}