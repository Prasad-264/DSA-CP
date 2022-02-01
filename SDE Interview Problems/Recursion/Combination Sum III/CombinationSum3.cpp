class Solution {
public:
  void combination(vector<vector<int>>& ans, vector<int> ds, int k, int n) {
    if (ds.size() == k && n == 0) { 
        ans.push_back(ds); 
        return; 
    }
    if (ds.size() < k) {
        for (int i = ds.empty() ? 1 : ds.back() + 1; i <= 9; i++) {
            if (n - i < 0) break;
            ds.push_back(i);
            combination(ans, ds, k, n - i);
            ds.pop_back();
        }
    }
  }
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> ds;
    combination(ans, ds, k, n);
    return ans;
  }
};