class Solution {
public:
    int maxArea(vector<int>& heights) {
        int areaMax = 0;
        int l = 0; int r = heights.size() - 1;
        while(l < r) {
            int currAreaMax = (r - l) * min(heights[l], heights[r]);
            areaMax = max(areaMax, currAreaMax);
            if(heights[l] <= heights[r]){
                l++;
            } else if(heights[l] > heights[r]){
                r--;
            }
        }
        return areaMax;
    }
};
