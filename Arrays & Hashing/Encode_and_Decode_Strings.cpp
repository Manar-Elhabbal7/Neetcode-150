// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto& st : strs) {
            // ex : 5/hello5/world
            encoded += to_string(st.size()) + '/' + st;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int idx = 0;
        while (idx < s.size()) {
            // to find the first / after the idx
            int j = s.find('/', idx);

            // len of the string to use in substr
            int len = stoi(s.substr(idx, j - idx));
            // slice from the idx with length of len
            ans.push_back(s.substr(j + 1, len));

            idx = 1 + len + j;
        }

        return ans;
    }
};
