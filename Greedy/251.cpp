#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  public:
  
    struct meet{
        int start;
        int finish;
        int index;
    };
  
    static bool cmp(const meet &a,const meet &b){
        return a.finish < b.finish;
    }
  
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        vector<meet> v;
        
        for(int i = 0 ;i< N; i++){
            meet obj;
            obj.start = S[i];
            obj.finish = F[i];
            obj.index = i+1;
            v.push_back(obj);
        }
        sort(v.begin(),v.end(),cmp);
        
        vector<int> ans;
        ans.push_back(v[0].index); // always take first ever meeting;
        auto prev = v[0];
        
        for(int i = 1;i< N;i++){
            auto &ele = v[i];
            if(ele.start > prev.finish){
                ans.push_back(ele.index);
                prev = v[i];
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};