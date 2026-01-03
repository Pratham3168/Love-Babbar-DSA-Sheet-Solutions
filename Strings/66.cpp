#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void getPermutations(vector<string> &ans, string &s,int index)
{
    if(index>=s.length()){
        ans.push_back(s);
        return;
    }
    int n = s.length();
    unordered_set<char> used;
    for (int j = index; j < n; j++)
    {
if (used.count(s[j])) continue;
            used.insert(s[j]);        swap(s[index], s[j]);
        getPermutations(ans,s,index+1);
        swap(s[index], s[j]);
    }
}
  
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> ans;
        getPermutations(ans,s,0);
        return ans;
    }
};
