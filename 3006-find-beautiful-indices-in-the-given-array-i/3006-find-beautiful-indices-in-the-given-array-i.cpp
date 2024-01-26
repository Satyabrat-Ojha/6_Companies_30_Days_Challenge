class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ai,bi,ans;
        int sn = s.size(), an = a.size(), bn = b.size();
        for(int i=0;i<=sn - an;i++)
            if(s.substr(i,a.size()) == a)
                ai.push_back(i);

        for(int i=0;i<=sn - bn;i++)
            if(s.substr(i,b.size()) == b)
                bi.push_back(i);

        if(bi.empty()) return ans;

        for(auto i:ai) {
            int it=lower_bound(bi.begin(),bi.end(),i)-bi.begin();
            if(it==bi.size()) {
                if(abs(bi[it-1] - i) <= k)
                    ans.push_back(i);
            }
            else if(it==0) {
                if(abs(bi[it] - i) <= k)
                    ans.push_back(i);
            }
            else {
                if(abs(bi[it-1] - i) <= k)
                    ans.push_back(i);
                else if(abs(bi[it] - i) <= k)
                    ans.push_back(i);
            }
        }
        return ans;
    }
};