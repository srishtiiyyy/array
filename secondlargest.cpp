#include<bits./stdc++.h>
using namespace std;
int secondlargest(int arr[],int n){
    int maxi=arr[0];
    int secondmax=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maxi){
            secondmax=maxi;
            maxi=arr[i];
        }
        else if(arr[i]<maxi && arr[i]>secondmax){
            secondmax=arr[i];
        }
    }
    if(secondmax==INT_MIN)return -1;
    return secondmax;}
    int main(){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"secondlargest is-"<<secondlargest(arr,n);
        return 0;
    }