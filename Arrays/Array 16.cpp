#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int cnt=0;
        int s=1;
        int e=nums.size()-1;
        int ans;
        while(s<=e){
            int mid = s+ (e-s)/2;
            cnt = 0;
            for(int num:nums){
                if(num<=mid){
                    cnt++;
                }
            }
            if(cnt<=mid){
                s=mid+1;
            }
            else{
                ans=mid;
                e=mid-1;
            }
        }
        return ans;
    }
};
