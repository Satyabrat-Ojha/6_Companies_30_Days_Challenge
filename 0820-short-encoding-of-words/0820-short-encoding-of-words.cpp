class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &word:words) reverse(word.begin(),word.end());
        sort(words.begin(),words.end());
        int ans = words[0].size()+1;
        for(int i=1;i<words.size();i++) {
            if(words[i].substr(0,words[i-1].size()) == words[i-1])
                ans += (int)words[i].size() - (int)words[i-1].size();
            else ans += words[i].size()+1;
        }
        return ans;
    }
};