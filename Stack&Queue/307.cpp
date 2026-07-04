#include <bits/stdc++.h>

class Solution {
	public:
	
	int floorDiv(int a, int b) {
		int q = a / b;
		int r = a % b;
		
		// If remainder exists and signs differ
		if (r != 0 && ((a < 0) != (b < 0)))
			q--;
		
		return q;
	}
	
	int evaluatePostfix(vector<string>& arr) {
		// code here
		stack<int> st;
		int i = 0 ;
		int n = arr.size() ;
		while (i < n) {
			string s = arr[i];
			if (s == "+" || s == "-" || s == "*" || s == "/" || s == "^") {
				int b = st.top(); st.pop();
				int a = st.top(); st.pop();
				
				int x = a;
				int y = b;
				
				int ans;
				
				if (s == "+")
					ans = x + y;
				else if (s == "-")
					ans = x - y;
				else if (s == "*")
					ans = x * y;
				else if (s == "/")
					ans = floorDiv(x,y);
				else
					ans = pow(x, y);
				
				st.push(ans);
			}
			else {
				st.push(stoi(s));
			}
			i++;
		}
		return st.top();
	}
};
