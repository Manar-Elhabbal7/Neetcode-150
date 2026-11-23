//Time Complexity : O(n)
//Space Complexity : O(n)

class Solution {
   public:
    bool isPalindrome(string& s) {
        string st = "";
        for (auto& c : s) {
            c = tolower(c);
            //isalnum checks if the character is alphapetic char or digit
            if (isalnum(c)) {
                st += c;
            }
        }

        int n = st.size();
        int l = 0, r = n - 1;

        while (l < r) {
            if (st[l] != st[r])
                return false;
            else {
                l++, r--;
            }
        }

        return true;
    }
};

//Time Complexity : O(n)
//Space Complexity : O(1)

class Solution {
   public:
    bool isPalindrome(string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r and !isalnum(s[l])) l++;
            while (l < r and !isalnum(s[r])) r--;
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++, r--;
        }
        return true;
    }
};

