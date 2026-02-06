#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
  
    int Inversioncnt =0 ;
  
  
      void Merge(vector<int> &arr, int l ,int mid,int r){
        int n1=mid-l+1;
        int n2=r-mid;
        vector<int> L(n1),R(n2);
        for(int i=0;i <n1;i++){
            L[i]=arr[l+i];
        }
        for(int j=0;j <n2;j++){
            R[j]=arr[mid+1+j];
        }
        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k]=L[i];
                i++;
                
            }
            else{   
                arr[k]=R[j];
                j++;
                Inversioncnt += (n1-i);
            }
            k++;
        }
        while(i<n1){
            arr[k++]=L[i++];
        }
        while(j<n2){
            arr[k++]=R[j++];
        }
    
    }
    void MergeSort(vector<int> &arr,int l,int r){
        if(l>=r){
            return ;
        }
        int mid=(l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        Merge(arr,l,mid,r);
    }
    
  
    int inversionCount(vector<int> &arr) {
        // Code Here
        Inversioncnt =0 ;
        MergeSort(arr,0,arr.size()-1);
        return Inversioncnt;
        
        
    }
};