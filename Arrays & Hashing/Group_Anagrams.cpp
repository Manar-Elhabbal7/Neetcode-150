// Time Compleixty : O(n* klogk)
// Space Complexity : O(n*k)

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        vector<vector<string>> ans;

        for (auto& word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }

        for (auto& [a, b] : groups) {
            ans.push_back(b);
        }

        return ans;
    }
};
