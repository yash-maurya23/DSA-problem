
class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(0, nums, currentSubset, result);

        return result;
    }

   private:
    void backtrack(int index, vector<int>& nums, vector<int>& currentSubset,
                   vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(currentSubset);
            return;
        }

        currentSubset.push_back(nums[index]);
        backtrack(index + 1, nums, currentSubset, result);

        currentSubset.pop_back();
        backtrack(index + 1, nums, currentSubset, result);
    }
};