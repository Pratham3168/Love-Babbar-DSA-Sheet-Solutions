// IMPLEMENTING THE DOUBLE-HELIX PROBLEM USING TWO POINTERS

#include<bits/stdc++.h>
using namespace std;


int findMaxSum(vector<int> a, vector<int> b, int n, int m){

    int sumA = 0, sumB = 0, total = 0;
    int i = 0, j = 0;

    while(i < n && j < m){

        if(a[i] < b[j]){
            sumA += a[i++];
        }
        else if(a[i] > b[j]){
            sumB += b[j++];
        }
        else{
            sumA += a[i++];
            sumB += b[j++];

            total += max(sumA, sumB);

            sumA = 0;
            sumB = 0;
        }
    }

    while(i < n) sumA += a[i++];
    while(j < m) sumB += b[j++];

    total += max(sumA, sumB);

    return total;
}



int main(){

    vector<int> a1 = {3,5,7,9,20,25,30,40,55,56,57,60,62};
    vector<int> b1 = {1,4,7,11,14,25,44,47,55,57,100};


    int ans =  findMaxSum(a1,b1,a1.size(),b1.size());

    cout<<"Max Sum obtained from this double helix sequence is : "<<ans<<endl;


    return 0;
}