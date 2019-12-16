#include "bfs.h"

char nextGreatestLetter_744(vector<char>& letters, char target){
    int min = 60;
    int flag = 0;
    for(auto c:letters){
        int tmp;
        if(c-target>0){
            if(c-target<min){
                min = c-target;
                flag = 0;
            }
        }else if(c-target<0){
            if(c-target+26<min){
                min = c-target+26;
                flag=1;
            }
        }
    }
    return flag?target+min-26:target+min;
}