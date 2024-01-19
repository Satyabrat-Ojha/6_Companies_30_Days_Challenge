class Solution {
public:
    bool isValidSerialization(string S) {
        if(S.size()==1 && S[0]=='#') return 1;
        if(S[0]=='#') return 0;

        string s = "1";
        for(int i=1;i<S.size();i++) {
            if(S[i]==',') continue;
            if(S[i]=='#') s+=S[i];
            else if(S[i-1]==',' || S[i-1]=='#') s+='1';
        }
        cout<<s;

        stack<pair<char,int>>q;
        q.push({s[0],2});
        int i = 1;
        while(!q.empty() && i<s.size()) {
            cout<<q.top().first<<" "<<q.top().second<<"\n";
            q.top().second--;
            if(q.top().second == 0) q.pop();
            if(s[i]!='#') q.push({s[i],2});
            i++;
        }
        return (q.empty() && i >= s.size());
    }
};