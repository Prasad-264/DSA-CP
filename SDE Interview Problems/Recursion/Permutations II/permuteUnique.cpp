/*
Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]


Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
// Same as Permutation I
// Using unordered_set

class Solution {
private:
    void func(int ind, vector<int>& nums, vector<vector<int>>& ans) {
        if(ind == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for (int i = ind; i < nums.size(); ++i) {
            if (st.count(nums[i]) == 1) continue;
            st.insert(nums[i]);
            swap(nums[i], nums[ind]);
            func(ind + 1, nums, ans);
            swap(nums[i], nums[ind]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        func(0, nums, ans);
        return ans; 
    }
};

// Without set

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        sort(begin(nums), end(nums));
        generatePermutations(nums, output, 0);
        return output;
    }
private:
    void generatePermutations(vector<int> nums, vector<vector<int>>& output, int idx) {
        if (idx == size(nums)) {
            output.emplace_back(nums);
        }
        for (int i = idx; i < size(nums); ++i) {
            if (i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            generatePermutations(nums, output, idx + 1);
        }
    }
};