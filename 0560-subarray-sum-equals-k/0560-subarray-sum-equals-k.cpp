class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int curr=0;
        unordered_map<int,int>mp;
        mp[0]=1;

        for(int num:nums){
            curr+=num;
            int need=curr-k;

            if(mp.count(need)){
                count+=mp[need];
            }
            mp[curr]++;
        }
        return count;
    }
};