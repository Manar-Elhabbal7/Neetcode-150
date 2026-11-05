// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto& val : nums) {
            mp[val]++;
        }

        for (auto& [a, b] : mp) {
            if (b > 1) return true;
        }
        return false;
    }
};
