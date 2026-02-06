// PROBLE NAME -  BISHU AND SOLDIERS

/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h> 
using namespace std;

int main(){

	int N;
	vector<int> s;
	int ele;
	int Q;
	cin>>N;
	for(int i =0;i<N;i++){
		cin>>ele;
		s.push_back(ele);
	}
	cin>>Q;
	vector<int> pow;
	for(int i =0;i<Q;i++){
		cin>>ele;
		pow.push_back(ele);
	}

	//checking if the values got it correct
	// cout<<N<<endl;
	// for(int ele:s){
	// 	cout<<ele<<" ";
	// }
	// cout<<endl;
	// cout<<Q<<endl;
	// for(int ele:pow){
	// 	cout<<ele<<endl;
	// }


	sort(s.begin(), s.end());

	vector<long long> pref(s.size());
	pref[0] = s[0];
	for (int i = 1; i < s.size(); i++) {
		pref[i] = pref[i - 1] + s[i];
	}

	for (int bpow : pow) {
    int idx = upper_bound(s.begin(), s.end(), bpow) - s.begin();
    int cnt = idx;
    long long sum = (idx > 0 ? pref[idx - 1] : 0);
    cout << cnt << " " << sum << endl;
}




	return 0;

}