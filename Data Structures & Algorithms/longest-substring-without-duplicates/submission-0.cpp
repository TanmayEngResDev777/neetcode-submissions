class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256,0);
        int l = 0, r = 0;
        int lols = 0;
        int n = s.length();

        while(r < n) {
            count[s[r]]++;
            while(count[s[r]] > 1) {
                count[s[l]]--;
                l++;
            }
            
            lols = max(lols, r - l + 1);
            r++;
        }

        return lols;
    }
};
