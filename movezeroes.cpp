#include<bits/stdc++.h>
using namespace std;
void movezeroes(vector<int> & arr){// BRUTE FORCE
    int n=arr.size();
    vector<int>temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
    int nz=temp.size();
    for(int i=0;i<nz;i++){
        arr[i]=temp[i];
    }
    for(int i=nz;i<n;i++){
        arr[i]=0;
    }
for(int i=0;i<n;i++){
    cout<<arr[i];
}
}
void movezeroesoptimal(vector<int> &arr){//OPTIMALLLL
int j=-1;
int n=arr.size();
for(int i=0;i<n;i++){
if(arr[i]==0){
    j=i;
    break;
}
}
if(j==-1)return;
for(int i=j+1;i<n;i++){
    if(arr[i]!=0){
        swap(arr[i],arr[j]);
        j++;
    }
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
  movezeroesoptimal(arr);
  return 0;
}