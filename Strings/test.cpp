#include <bits/stdc++.h>
using namespace std;

void getPermutations(vector<string> &ans, string &s,int index)
{
    if(index>=s.length()){
        ans.push_back(s);
        return;
    }
    int n = s.length();
    for (int j = index; j < n; j++)
    {
        swap(s[index], s[j]);
        getPermutations(ans,s,index+1);
        swap(s[j], s[index]);
    }
}

int main()
{
    string s = "abc";

    vector<string> ans;
    getPermutations(ans, s,0);
    for (string ele : ans)
    {
        cout << ele << " ";
    }
    return 0;
}