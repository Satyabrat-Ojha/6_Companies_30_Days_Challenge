class Solution {
    map<vector<int>,int>m;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ans = 0, n = price.size();
        for(int i=0;i<n;i++) ans+=price[i]*needs[i];

        for(auto offer : special) {
            bool flag=1;
            for(int i=0;i<n;i++) {
                if(needs[i]<offer[i]) {
                    flag=0;
                    break;
                }
            }

            if(flag) {
                for(int i=0;i<n;i++) needs[i]-=offer[i];
                
                int A = offer[n];
                if(m[needs]) A+=m[needs];
                else A+=m[needs]=shoppingOffers(price,special,needs);
                ans = min(A,ans);
                
                for(int i=0;i<n;i++) needs[i]+=offer[i];
            }
        }

        return ans;
    }
};