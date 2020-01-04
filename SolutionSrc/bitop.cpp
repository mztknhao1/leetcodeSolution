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