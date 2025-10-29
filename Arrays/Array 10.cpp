//I THOUGHT OF THIS TWO POINTER APPROACH BY MYSELF
//OTHER THREE APPROACHES ARE IN NOTEBOOK INCLUDING THE QUICK SORT APPROACH


#include<iostream>
#include<vector>
using namespace std;

void Changeplaces(vector<int> &arr, int n){
    int l=0;
    int r=arr.size()-1;

    while(l<=r){
        if(arr[l] < 0 && arr[r]>0){
            l++;
            r--;
        }
        else if(arr[l]>0 && arr[r]<0){
            swap(arr[l],arr[r]);
            l++;
            r--;
        }
        else if(arr[l]<0 && arr[r]<0){
            l++;
        }
        else if(arr[l]>0 && arr[r]>0){
            r--;
        }
    }
}

int main(){
    vector<int> arr;
    arr.push_back(-12);
    arr.push_back(11);
    arr.push_back(-13);
    arr.push_back(-5);
    arr.push_back(6);
    arr.push_back(-7);
    arr.push_back(5);
    arr.push_back(-3);
    arr.push_back(6);

    cout<<"Before any changes : ";
    for(int ele:arr){
        cout<<ele<<" ";
    }

    cout<<"After Changes : ";
    for(int ele: arr){
        cout<<ele<<" ";
    }

    return 0;
}