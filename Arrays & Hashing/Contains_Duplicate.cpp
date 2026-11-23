// Time Complexity : O(n)
// Space Complexity : O(n)


class Solution {
   public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;

        for (auto& val : nums) {
            mp[val]++;
            if (mp[val] > 1) return true;
        }

        return false;
    }
};

//Time complexity = O(n)
//Space complexity = O(n)

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(auto &val : nums){
           //st.insert(val) -> return pair {iterator , bool} if bool = false so it will not be added as it is already in the st 
            if(!st.insert(val).second) return true;
        }
        return false;
    }
};
