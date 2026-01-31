#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>& arr) {
    int s = 0, e = arr.size() - 1;

    while (s < e) {
        int mid = s + (e - s) / 2;

        if (arr[mid] > arr[e]) {
            s = mid + 1;
        } else {
            e = mid;
        }
    }
    return s;
}


    int BinarySearch(vector<int> &arr,int s,int e,int target){
        int mid = s + (e-s)/2;

        while(s<=e){
            if(arr[mid] ==  target){
                return mid;
            }
            else if(arr[mid] > target){
                e = mid-1;
            }
            else {
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return -1;

    }

    int getRange(vector<int> &arr , int target){
        
        int n = arr.size();

        int pivot = getPivot(arr);

        if(target >= arr[pivot] && target <=arr[n-1]){
            return BinarySearch(arr,pivot,n-1,target);
        }
        else {
            return BinarySearch(arr,0,pivot-1,target);
        }

    }
int main(){
    vector<int> arr={7,8,9,0,2,3};
    int a=getRange(arr,7);
    cout<<"Position is : "<<a<<endl;
}