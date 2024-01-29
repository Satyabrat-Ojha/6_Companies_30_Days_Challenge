class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(auto word:dictionary)
            if(word.size()>ans.size() || (word.size()==ans.size() && word<ans))
                if(check(word,s)) ans = word;
        return ans;
    }

    bool check(string w,string s) {
        while(w.size() && s.size()) {
            if(w.back() == s.back()) w.pop_back();
            s.pop_back();
        }
        return w.empty();
    }
};