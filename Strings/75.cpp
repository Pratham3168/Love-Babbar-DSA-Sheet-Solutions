#include<bits/stdc++.h>
using namespace std;

void solve(string s, string str[], string &ans){
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            ans+='0';
            continue;
        }
        int temp = s[i]-'A';
        ans+=str[temp];
    }
}



string printSequence(string S) {
    string str[]
        = { "2",   "22",  "222", "3",   "33",   "333", "4",
            "44",  "444", "5",   "55",  "555",  "6",   "66",
            "666", "7",   "77",  "777", "7777", "8",   "88",
            "888", "9",   "99",  "999", "9999" };
            
    string ans;
    solve(S,str,ans);
    return ans;
}