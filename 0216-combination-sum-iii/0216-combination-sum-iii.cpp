class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        vector<int> temp;
        helper(1,k,n,temp);
        return res;
    }

    void helper(int i, int k, int n, vector<int> &temp) {
        if(k==0 && n==0) {
            res.push_back(temp);
            return;
        }

        if(n<0 || k<0 || i>9) return;

        temp.push_back(i);
        helper(i+1, k-1, n-i, temp);
        temp.pop_back();
        helper(i+1, k, n, temp);
    }
};