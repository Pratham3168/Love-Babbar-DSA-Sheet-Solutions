#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];   // compare by start times
        });
        vector<vector<int>> ans;
        vector<int> temp(2);
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int i=0;
        temp = intervals[0];
        for(int i = 1;i<intervals.size();i++){
            if(intervals[i][0]<=temp[1]){
                temp[0] = min(intervals[i][0],temp[0]);
                temp[1] = max(intervals[i][1],temp[1]);
            }
            else{
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};