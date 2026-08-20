class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            int c = count(nums.begin(), nums.end(), nums[i]);
            
            if (c > n / 3) {
               
                if (count(result.begin(), result.end(), nums[i]) == 0) {
                    result.push_back(nums[i]);
                }
            }
        }
        
        return result;
    }
};
