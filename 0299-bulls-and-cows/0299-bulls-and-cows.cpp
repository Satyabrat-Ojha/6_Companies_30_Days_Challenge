class Solution {
public:
    string getHint(string secret, string guess) {
        int b=0,c=0,n=secret.size();
        map<char,int>m;
        for(int i=0;i<n;i++) {
            if(secret[i]==guess[i]) b++;
            else m[secret[i]]++;
        }
        for(int i=0;i<n;i++) {
            if(secret[i]!=guess[i] && m[guess[i]]) {
                c++;
                m[guess[i]]--;
            }
        }

        string ans = to_string(b)+"A"+to_string(c)+"B";
        return ans;
    }
};