#include<set>
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> mySet;
        for(int i : a){
            mySet.insert(i);
        }
        for(int j : b){
            mySet.insert(j);
        }
        vector<int> result;
        for(int ele : mySet){
            result.push_back(ele);
        }
        return result;
    }
};