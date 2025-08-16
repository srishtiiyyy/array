//array is sorted return  1 based index
//use two pointer approach
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int i = 0, j = n - 1;
    while(i < j){
        if(numbers[i] + numbers[j] == target)
            return {i+1, j+1}; // return 1-based indices
        else if(numbers[i] + numbers[j] > target)
            j--;
        else
            i++;
    }
    return {-1, -1};
}

int main(){
    int n, target;
    cout << "Enter size of sorted array: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter sorted array elements:\n";
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> ans = twoSum(numbers, target);

    cout << "Indices (1-based): " << ans[0] << " " << ans[1] << endl;

    return 0;
}
