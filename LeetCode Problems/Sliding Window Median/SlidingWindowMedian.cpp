class Solution {
public:
    int k;
    double median(vector<int>& v){
        if(k%2==0){
            double a=v[k/2];
            double b=v[k/2-1];
            return (a+b)/2;
        }
        return v[k/2];
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        this->k=k;
        vector<int> v;
        vector<double> ans;
        int r=0,l=0;
        while(r<k)
            v.push_back(nums[r++]);
        sort(v.begin(),v.end());
        ans.push_back(median(v));
        for(int i=r;i<nums.size();i++,l++){
            
            auto pos=lower_bound(v.begin(),v.end(),nums[l]);
            v.erase(pos);
            auto ins=upper_bound(v.begin(),v.end(),nums[i]);
            v.insert(ins,nums[i]);
            ans.push_back(median(v));
        }
        return ans;
    }
};