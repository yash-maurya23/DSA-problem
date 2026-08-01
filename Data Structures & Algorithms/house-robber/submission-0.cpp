
class Solution {
public:
    int rob(vector<int>& nums) {
        int prevMax = 0; 
        int currMax = 0; 
        
        for (int money : nums) {
        
            int newMax = max(currMax, prevMax + money);
            prevMax = currMax;
            currMax = newMax;
        }
        
        return currMax;
    }
};
