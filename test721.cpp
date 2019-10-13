#include"Solution.h"
#include"utils.h"

using std::cout;
using std::endl;


int main(){
    Solution s;
    vector<vector<std::string>> acounts;
    vector<std::string> acount1={"John","johnsmith@mail.com", "john00@mail.com"};
    acounts.push_back(acount1);
    vector<std::string> acount2={"John", "johnnybravo@mail.com"};
    acounts.push_back(acount2);
    vector<std::string> acount3={"John", "johnsmith@mail.com", "john_newyork@mail.com"};
    acounts.push_back(acount3);
    vector<std::string> acount4={"Mary", "mary@mail.com"};
    acounts.push_back(acount4);

    vector<vector<std::string>> merged;
    merged = s.acountsMerge_q721(acounts);
    
    for(int i=0;i<merged.size();i++){
        for(int j=0;j<merged[i].size();j++){
            cout << merged[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
    
    
}