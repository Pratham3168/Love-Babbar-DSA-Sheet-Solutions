#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;


//SOLUTION 1
// class Solution {
// public:

//     int hashvalue(string s, int RADIX, int m) {
//     if (s.length() < m) return -1;

//     long long hashValue = 0;
//     long long factor = 1;

//     for (int i = m - 1; i >= 0; i--) {
//         hashValue = (hashValue + ((s[i] - 'a') * factor) % MOD) % MOD;
//         factor = (factor * RADIX) % MOD;
//     }
//     return (int)hashValue;
// }


//     int strStr(string haystack,string needle){

//     int n = haystack.length();
//     int m = needle.length();

//     if(n<m){
//         return -1;
//     }

//     int RADIX = 26;
//     long long MAXWEIGHT = 1;
//     for(int i=0;i<m-1;i++){
//         MAXWEIGHT = (MAXWEIGHT * RADIX) % MOD;
//     }

//     int hashNeedle = hashvalue(needle,RADIX,m);
    
//     for(int i=0;i<=n-m;i++){
//         int hashHay = hashvalue(haystack.substr(i,m),RADIX,m);

//         if(hashHay == hashNeedle){
//             bool match = true;
//             for(int j=0;j<m;j++){
//                 if(haystack[j+i]!=needle[j]){
//                     match = false;
//                     break;
//                 }
//             }
//             if(match){
//                 return i;
//             }
//         }
//     }

//     return -1;
// }
// };







//==================SOLUTION 2(SAME ALGORITHM BUT WITH SLIGHT DIFFERENCES)===========================
// #include<bits/stdc++.h>
// #define MOD 1000000007

// class Solution {
//   public:
  
     
  
//     vector<int> search(string &pat, string &txt) {
//         int n = txt.size();
//         int m = pat.size();
//         vector<int> ans;

//         if (m > n) return ans;

//         int RADIX = 26;
//         long long hashPat = 0, hashTxt = 0;
//         long long power = 1; // RADIX^(m-1)

//         // compute RADIX^(m-1)
//         for (int i = 0; i < m - 1; i++)
//             power = (power * RADIX) % MOD;

//         // initial hashes
//         for (int i = 0; i < m; i++) {
//             hashPat = (hashPat * RADIX + (pat[i] - 'a')) % MOD;
//             hashTxt = (hashTxt * RADIX + (txt[i] - 'a')) % MOD;
//         }

//         // sliding window
//         for (int i = 0; i <= n - m; i++) {

//             // hash match → verify
//             if (hashPat == hashTxt) {
//                 bool match = true;
//                 for (int j = 0; j < m; j++) {
//                     if (txt[i + j] != pat[j]) {
//                         match = false;
//                         break;
//                     }
//                 }
//                 if (match) ans.push_back(i);
//             }

//             // roll hash
//             if (i < n - m) {
//                 hashTxt = (hashTxt - (txt[i] - 'a') * power) % MOD;
//                 if (hashTxt < 0) hashTxt += MOD;

//                 hashTxt = (hashTxt * RADIX + (txt[i + m] - 'a')) % MOD;
//             }
//         }

//         return ans;
//     }
// };