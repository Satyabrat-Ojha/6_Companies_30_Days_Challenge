class Solution {
    unordered_map<char,string> letters = {
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };
    vector<string>ans;

public:
    vector<string> letterCombinations(string digits) {
        ans.clear();
        solve(0,"",digits);
        return ans;
    }

    void solve(int curr, string s, string digits) {
        if(curr == digits.size()) {
            if(!s.empty())
                ans.push_back(s);
            return;
        }

        char c = digits[curr++];
        string l = letters[c];

        for(auto e:l) {
            s.push_back(e);
            solve(curr,s,digits);
            s.pop_back();
        }
    }
};