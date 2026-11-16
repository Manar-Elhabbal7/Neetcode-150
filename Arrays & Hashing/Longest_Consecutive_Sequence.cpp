// Time Complexity : O(n log n)
// Space Complexity : O(n)

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        set<int>st(nums.begin(),nums.end()); 
        vector<int> v(st.begin(),st.end());

        int cnt = 1, ans = 0;
        for (int i = 1; i < v.size(); i++) {
            if (abs(v[i] - v[i - 1]) == 1) {
                cnt++;
            }
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};
