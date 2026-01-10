#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

//CALCULATING THE HASH VALUE OF THE NEEDLE
int hashvalue(string s,int RADIX,int m){
    if(s.length() < m) return -1;
    int hashValue = 0;
    int factor = 1;
    for(int i=m-1;i>=0;i--){
        hashValue = (hashValue + ((s[i]-'a') * factor)%MOD) % MOD;
        factor = (factor*RADIX)%MOD;
    }
    return hashValue;
}


//IMPLEMENTATION OF RABIN KARP ALGORITHM
int strStr(string haystack,string needle){

    int n = haystack.length();
    int m = needle.length();

    if(n<m){
        return -1;
    }

    int RADIX = 26;
    long long MAXWEIGHT = 1;
    for(int i=0;i<m-1;i++){
        MAXWEIGHT = (MAXWEIGHT * RADIX) % MOD;
    }

    int hashNeedle = hashvalue(needle,RADIX,m);
    
    for(int i=0;i<=n-m;i++){
        int hashHay = hashvalue(haystack.substr(i,m),RADIX,m);

        if(hashHay == hashNeedle){
            bool match = true;
            for(int j=0;j<m;j++){
                if(haystack[j+i]!=needle[j]){
                    match = false;
                    break;
                }
            }
            if(match){
                return i;
            }
        }
    }

    return -1;
}

int main(){

    string haystack = "sadbutsad";
    string needle = "sad";

    cout<<"BEFORE"<<endl;
    cout.flush();
    
    int index = strStr(haystack,needle);

    cout<<"AFTER"<<endl;

    cout<<"Index of the occurence of "<<needle<<" in the "<<haystack<<" is : "<<index<<endl;

    return 0;

}