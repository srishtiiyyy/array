#include<bits/stdc++.h>
using namespace std;
int linearsearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
        return -1;
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the element to search: ";
    cin>>key;
    
    int result = linearsearch(arr, n, key);
    
    if(result != -1){
        cout<<"Element found at index: "<<result<<endl;
    } else {
        cout<<"Element not found in the array."<<endl;
    }
    
    return 0;
}