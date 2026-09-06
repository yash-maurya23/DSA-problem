class Solution {
public:
    string minWindow(string s, string t) {

        if (s.length() < t.length())
            return "";

        unordered_map<char, int> targetMap;

        for (char c : t) {
            targetMap[c]++;
        }

        int required = targetMap.size();

        unordered_map<char, int> windowMap;

        int formed = 0;

        int l = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        for (int r = 0; r < s.length(); r++) {

            char rightchar = s[r];

            windowMap[rightchar]++;

            if (targetMap.count(rightchar) &&
                windowMap[rightchar] == targetMap[rightchar]) {

                formed++;
            }

            while (formed == required) {

                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    startIdx = l;
                }

                char leftChar = s[l];

                windowMap[leftChar]--;

                if (targetMap.count(leftChar) &&
                    windowMap[leftChar] < targetMap[leftChar]) {

                    formed--;
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};