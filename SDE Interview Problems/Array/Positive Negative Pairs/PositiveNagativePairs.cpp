#include <bits/stdc++.h>
#include <unordered_map>
#include <math.h>
using namespace std;

class Solution{
  public:
    //Function to return list containing all the pairs having both
    //negative and positive values of a number in the array.
    vector <int> findPairs(int arr[], int n) {
        map<int, int> m;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            m[arr[i]]++;
            if(m[-arr[i]] > 0 && arr[i]!=0){
                int x = abs(arr[i]);
                // cout<< "Value of x : " << x << endl;
                ans.push_back(-x);
                ans.push_back(x);
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        vector <int> res = obj.findPairs(arr, n);
    	if(res.size() != 0)
    	{
    		for (int i : res) 
            	cout << i << " ";
        	cout << endl;	
    	}
    	else
    		cout << 0 << endl;
    }

    return 0;
}  