#include <bits/stdc++.h>

class Solution {
	public:
	
	vector<int> maxOfSubarrays(vector<int>& arr, int k) {
		// code here
		
		int n = arr.size();
		
		if (k == 1) {
			return arr;
		}
		
		priority_queue<pair<int, int>> pq;
		int i = 0 ;
		int j = k - 1;
		
		vector<int> ans;
		
		for (int idx = 0; idx <= j ; idx++) {
			pq.push({arr[idx], idx});
		}
		
		while (j<n) {
			
			while (!pq.empty() && pq.top().second < i)
				pq.pop();
			ans.push_back(pq.top().first);
			i++;
			j++;
			if (j<n) {
				pq.push({arr[j], j});
			}
		}
		
		return ans;
		
	}
};
