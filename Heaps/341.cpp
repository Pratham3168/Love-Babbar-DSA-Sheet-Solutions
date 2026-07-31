class Solution {
	public:
	vector<int> mergeArrays(vector<vector<int>> &mat) {
		// Code here
		vector<pair<int, pair<int, int>> > temp;
		
		for (int i = 0; i < mat.size() ; i++) {
			temp.push_back({ mat[i][0], {i, 0}});
		}
		
		priority_queue<pair<int, pair<int, int>>,
		vector<pair<int, pair<int, int>>>,
		greater<pair<int, pair<int, int>>>> pq(temp.begin(), temp.end());
		
		vector<int> ans;
		
		while (!pq.empty()) {
			
			pair<int, pair<int, int>> top = pq.top();
			pq.pop();
			
			int value = top.first;
			int row = top.second.first;
			int col = top.second.second;
			
			ans.push_back(value);
			
			if (col + 1 < mat[row].size()) {
				pq.push({mat[row][col + 1], {row, col + 1}});
			}
			
		}
		
		return ans;
	}
};
