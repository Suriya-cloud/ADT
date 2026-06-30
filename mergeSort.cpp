#include <bits/stdc++.h>
using namespace std;
int merge(vector<int>&arr, int left, int mid, int right){
    int n=mid-left+1;
    int m=right-mid;
    vector<int>L(n);
    vector<int>R(m);
    for (int i=0; i<n; i++){
        L[i]=arr[left+i];
    }
    for(int i=0; i<m; i++){
        R[i]=arr[mid+i+1];
    }
    int i=0, j=0, k=left;
    while(i<n && j<m){
        if (L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }
    while(i<n){
        arr[k++]=L[i++];
    }
    while(j<m){
        arr[k++]=R[j++];
    }
    return 0;
}
void mergeSort(vector<int>&arr, int left, int right){
    if(left>=right){
        return;
    }
    int mid = left+(right-left)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergeSort(arr, 0, n-1);
    for (int i=0; i<n; i++){
        cout<<arr[i];
    }

}