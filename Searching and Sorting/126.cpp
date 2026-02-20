//IMPLEMENTING THE EKO SPOJ APPROACH


#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr,int mid,int M){

    int sum =0;

    for(int i =0 ;i<arr.size();i++){

        if(arr[i] >= mid){
            sum += arr[i] - mid;
        }

    }

    if(sum >= M){
        return true;
    }
    
    return false;

}


int main(){

    vector<int> arr = {4,42,40,26,46};
    int M = 20;
    int ans = 0 ;
    int s = 0;
    int e = 0;

    for(int ele:arr){
        e = max(ele,e);
    }

    int mid = s + (e-s)/2;

    while(s<=e){
        mid = s + (e-s)/2;

        if(isPossible(arr,mid,M)){

            ans = mid;
            s = mid+1;

        }
        else{
            e = mid-1;
        }

    }

    cout<<ans;

    return 0;

}