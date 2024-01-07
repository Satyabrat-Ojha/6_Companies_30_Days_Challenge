class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int c=0,s=0;
                for(int it=i-1;it<n && it<=i+1;it++) {
                    for(int jt=j-1;jt<m && jt<=j+1;jt++) {
                        if(it<0 || jt<0) continue;
                        c++;
                        s+=img[it][jt];
                    }
                }
                v[i][j]=s/c;
            }
        }
        return v;
    }
};