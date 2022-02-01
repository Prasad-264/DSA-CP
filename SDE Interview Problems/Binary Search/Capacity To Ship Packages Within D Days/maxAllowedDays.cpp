class Solution {
private:
    bool isPossible(vector<int>& weights, int maxAllowed, int days) {
        int sum = 0;
        int cnt = 1;
        for(auto it : weights) {
            if(it > maxAllowed) return false;
            if(sum + it > maxAllowed) {
                sum = it;
                cnt += 1;
            }
            else {
                sum += it;
            }
        }
        return cnt <= days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1; 
        int high = 0;
        for(auto it: weights) high += it;
        int ans = high;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(isPossible(weights, mid, days)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};