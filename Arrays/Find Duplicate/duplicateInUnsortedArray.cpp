#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int i, int j) {
	int temp = arr[i];
   	arr[i] = arr[j];
   	arr[j] = temp;
}

int findDuplicate(vector<int> &arr, int n){
	int i = 0;
   	while (i < n) {
		if (arr[i] != i+1) {
			int correct = arr[i] - 1;
           	if (arr[i] != arr[correct]) 
            	swap(arr, i, correct);
            else 
               	return arr[i];
        }
		else {
           i++;
       }
   }
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    findDuplicate(arr, n);

}