#include<bits/stdc++.h>
using namespace std;
void rotate(vector<int> &arr){
    int n=arr.size();
    int a=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=a;
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
int main(){
int n;
cin>>n;
vector<int>arr(n);
for(int i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"left rotate by one :";
rotate(arr);

return 0;
}