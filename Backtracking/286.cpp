class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& arr, int target, int start) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < arr.size(); i++) {

            if (arr[i] > target) break;   // pruning

            temp.push_back(arr[i]);
            solve(arr, target - arr[i], i); // reuse allowed
            temp.pop_back();
        }
    }

    vector<vector<int>> targetSumComb(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); // required for pruning
        ans.clear();
        temp.clear();
        solve(arr, target, 0);
        return ans;
    }
};