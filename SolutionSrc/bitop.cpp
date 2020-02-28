#include "bitop.h"


int maxFreq_q1297(string s, int maxLetters, int minSize, int maxSize){
    int len = s.size();
    int i=0;
    std::unordered_map<string,int> m;
    for(;i<len-minSize+1;i++){
        string tmp = s.substr(i,minSize);
        std::cout << tmp << std::endl;
        if(m.find(tmp)!=m.end()){
            m[tmp]++;
        }
        else{
            m[tmp] = 1;
        }
    }
    int ans=0;
    for(auto i:m){
        std::cout<<i.first<<":"<<i.second<<std::endl;
        if(check_q1297(i.first,maxLetters)){
            ans = (ans<i.second)?i.second:ans;
        }
    }
    return ans;
}

bool check_q1297(string s,int maxLetters){
    int n=0;
    std::unordered_map<char,bool> m;
    for(auto i:s){
        if(m.find(i)!=m.end()){
            continue;
        }else{
            m[i] = true;
            n++;
        }
    }
    return n<=maxLetters;
}

int divide_q29(int dividend, int divisor){
    if(dividend==INT32_MIN && divisor==-1) return INT32_MAX;
    if(dividend==0) return 0;
    if(divisor==1) return dividend;
    if(divisor==-1) return -dividend;

    int negetive = ((dividend ^ divisor) < 0);
    int result = 0;

    unsigned int tmpend = dividend == INT32_MIN?INT32_MIN:abs(dividend);
    unsigned int tmpor = divisor == INT32_MIN?INT32_MIN:abs(divisor);

    for(int i=31;i>=0;i--){
        if((tmpend>>i)>=tmpor){
            result += ((unsigned int)1) << i;
            tmpend-= tmpor << i;
        }
    }
    if(result == INT32_MIN) return INT32_MIN;
    else return negetive?-(int)result:(int)result;
}