class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());

        int ans = 0;
        for(auto e:arr1) {
            bool flag=1;
            for(auto x:arr2) {
                if(abs(e-x)<=d) {
                    flag=0;
                    break;
                }
            }
            ans+=flag;
        }

        return ans;
    }
};