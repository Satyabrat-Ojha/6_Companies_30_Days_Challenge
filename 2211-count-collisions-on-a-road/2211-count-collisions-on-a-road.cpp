class Solution {
public:
    int countCollisions(string s) {
        bool block = 0;
        int R=0;
        int ans = 0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='R') R++;
            if(s[i]=='S') {
                ans+=R;
                R=0;
                block=1;
            }
            if(s[i]=='L') {
                if(!R && !block) continue;
                block=1;
                ans+=1+R;
                R=0;
            }
        }
        return ans;
    }
};