// Time Complexity : O(n^2)
// Space Complexity : O(n)
// TLE

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            int answer = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) answer *= nums[j];  
            }
            ans.push_back(answer);
        }
        return ans;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n);
        vector<int> ans(n);

        prefix[0] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }
        return ans;
    }
};
