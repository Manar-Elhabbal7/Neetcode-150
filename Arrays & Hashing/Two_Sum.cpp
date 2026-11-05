//Soultion 1

// Time Complexity : O(n^2)
// Space Complexity : O(1)

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

// Solution 2 

// Time Complexity : O(n^2)
// Space Complexity : O(1)

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        int l = 0, r = 1, n = nums.size();

        while (l < n) {
            int num1 = nums[l];
            for (int i = r; i < n; i++) {
                if (num1 + nums[i] == target) {
                    ans.push_back(l);
                    ans.push_back(i);
                    return ans;
                }
            }
            l++;
            r = l + 1;
        }
        return ans;
    }
};

// Solution 3 Optimized

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valIndex;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (valIndex.find(complement) != valIndex.end()) {
                return {valIndex[complement], i};
            }
            valIndex[nums[i]] = i;
        }
        return {};
    }
};
