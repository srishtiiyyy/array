#include<bits/stdc++.h>
using namespace std;
int maxones(vector<int>arr){
    int n=arr.size();
    int cnt=0,maxi=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
        }
        else{
            cnt=0;
        }
    }
    return maxi;
}
int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"max consecutive ones is "<<maxones(arr);
    return 0;

}