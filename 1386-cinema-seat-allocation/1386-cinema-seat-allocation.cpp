class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& s) {
        int ans = n*2;
        sort(s.begin(),s.end());
        vector<vector<int>> v;
        v.push_back({s[0][1]});
        for(int i=1;i<s.size();i++) {
            if(s[i][0]==s[i-1][0]) v.back().push_back(s[i][1]);
            else v.push_back({s[i][1]});
        }

        for(auto row:v) {
            int c = count(row);
            int d = 2 - c;
            ans -= d;
        }
        return ans;
    }

    int count(vector<int> row) {
        int c=0,ans=0;
        vector<int> v(11, 1);
        for(auto seat:row) v[seat] = 0;
        for(int i=1;i<=10;i++) {
            if(v[i]) c++;
            else c=0;

            if(c==4) {
                ans++;
                c=0;
            }

            if(i==3 || i==7) {
                if(c==3 || c==2) c=2;
                else c=0;
            }
        }

        return ans;
    }
};