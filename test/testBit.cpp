#include "bitop.h"

int main(){
    string s="aababcaab";
    int maxLetters = 2;
    int minSize = 3;
    int maxSize = 4;
    int ans = maxFreq_q1297(s,maxLetters,minSize,maxSize);
    return ans;
}