#include<bits/stdc++.h>
using namespace std;
void reversearray(vector<int>&nums,int start,int end){
    while(start<end){
        swap(nums[start],nums[end]);
        start++;
        end--;
    }
}
void leftrotatebyd(vector<int> &nums,int d){
    int n=nums.size();
    d=d%n;
    reversearray(nums,0,d-1);
    reversearray(nums,d,n-1);
    reversearray(nums,0,n-1);
    for(int i=0;i<n;i++){
        cout<<nums[i];
    }
}
int main(){
    int n;
    cout<<"ENTER NUMBER OF ELEMENTS:";
    cin>>n;
    cout<<"enter places";
    int d;
    cin>>d;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"ROTATED ARRAY:";
    leftrotatebyd(nums,d);
    return 0;
}