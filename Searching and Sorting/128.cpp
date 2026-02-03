// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int inSequence(int a, int b, int c) {
        // code here
        return ((b-a)%c == 0)?true:false;
    }
};