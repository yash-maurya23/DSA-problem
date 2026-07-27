class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1freq(26, 0);
        vector<int> winfreq(26, 0);
         if (s1.length() > s2.length()) return false;

        for (char c : s1) s1freq[c - 'a']++;
        for (int i = 0; i < s1.length(); i++) winfreq[s2[i] - 'a']++;

        if (s1freq == winfreq) return true;

        for (int i = s1.length(); i < s2.length(); i++) {
            winfreq[s2[i] - 'a']++;
            winfreq[s2[i - s1.length() ]- 'a']--;
            if (s1freq == winfreq) return true;
        }
        return false;
    }
};
