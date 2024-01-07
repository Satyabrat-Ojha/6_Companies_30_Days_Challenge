class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        for(int i=0;i+9<s.size();i++) {
            m[s.substr(i,10)]++;
        }

        vector<string> ans;
        for(auto e:m) {
            if(e.second>1) {
                ans.push_back(e.first);
            }
        }
        return ans;
    }
};