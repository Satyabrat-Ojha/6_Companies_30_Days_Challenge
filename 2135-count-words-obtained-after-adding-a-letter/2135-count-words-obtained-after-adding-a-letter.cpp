class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        for(auto &s:startWords) sort(s.begin(),s.end());
        for(auto &s:targetWords) sort(s.begin(),s.end());

        int ans = 0;
        set<string>st;
        for(auto s:startWords) st.insert(s);
        
        for(string s : targetWords)
            ans+=check(s,st);

        return ans;
    }

    bool check(string s, set<string>& st) {
        map<char,int>m;
        for(char c:s) m[c]++;
        for(int i=0;i<s.size();i++) {
            if(m[s[i]] != 1) continue;
            string prefix = (i == 0) ? "" : s.substr(0,i);
            string suffix = (i == s.size()-1) ? "" : s.substr(i+1);
            cout<<prefix+suffix<<" ";
            if(st.find(prefix + suffix) != st.end()) return 1;
        }
        return 0;
    }
};