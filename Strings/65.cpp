//TO DO THIS QUESTION , WE WILL USE RECURSION :-
//WE WILL HAVE TWO CHOICES ON EVERY ELEMENT IN A STRING - EITHER INCLUDE IT OR EXCLUDE IT

#include<bits/stdc++.h>
using namespace std;


void solve(string str,string out,int index,vector<string> &ans){
    if(index>=str.length()){
        if(out.length()>=0){
            ans.push_back(out);
            return ;
        }
    }

    //EXCLUDE
    solve(str,out,index+1,ans);

    //INCLUDE
    out.push_back(str[index]);
    solve(str,out,index+1,ans);
}   

vector<string> subsequences(string str){
    string out = "";
    int index = 0;
    vector<string> ans;

    solve(str,out,index,ans);
    return ans;
}

int main(){
    string str = "abc";
    vector<string> result = subsequences(str);
    for(string ele:result){
        cout<<ele<<"  ";
    }
}