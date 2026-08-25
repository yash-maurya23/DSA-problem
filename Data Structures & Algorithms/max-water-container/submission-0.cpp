class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max_water = 0;

        while (left < right) {
            int width = right - left;

            int current_height = min(heights[left], heights[right]);

            int current_water = current_height * width;
            max_water = max(max_water, current_water);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};
