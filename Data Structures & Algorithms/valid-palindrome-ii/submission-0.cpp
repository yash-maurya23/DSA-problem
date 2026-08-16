class Solution {
public:
bool check(string s, int l, int r){
     while (l < r) {
            if (s[l] != s[r]) {
                return false; 
            }
            l++;
            r--;
        }
        return true;
}
public:
    bool validPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        while(l<r){
            if(s[l] ==s[r]){
                l++;
                r--;
            }
            else {
                return check(s,l+1,r) || check(s,l,r-1);
            }
        }
        return true;
    }
};