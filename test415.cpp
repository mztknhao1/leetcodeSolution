#include"Solution.h"

int main(int argc, const char*argv[]){
    std::string s1=argv[1];
    std::string s2=argv[2];
    Solution s;
    std::string test=s.addString_q415(s1,s2);
    std::cout<<test<<std::endl;
    return 0;
}