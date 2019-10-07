#include"Solution.h"
#include"utils.h"

using std::cout;
using std::endl;

int main(){
    Solution s;
    std::string test="aab";
    int n = s.lengthOfLongestSubstring_q3(test);
    cout << n <<endl;
    return 0;
}