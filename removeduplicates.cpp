#include<bits./stdc++.h>
using namespace std;
int removedup(vector<int> & arr){
    int n=arr.size();
  int i=0;
  for(int j=i+1;j<n;j++){
    if(arr[j]!=arr[i]){
        arr[i+1]=arr[j];
        i++;
    }
  }
  return i+1;
}
   
    int main(){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"size of new array:"<<removedup(arr);
        return 0;
    }