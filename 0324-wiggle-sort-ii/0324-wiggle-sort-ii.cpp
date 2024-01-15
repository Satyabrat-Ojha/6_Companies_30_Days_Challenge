class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v = nums;
        int n = v.size();
        sort(v.begin(),v.end(),greater<int>());
        int x=0;
        for(int i=0;i<n;i++) {
            
            if(i+i+1<n) nums[i+i+1]=v[i];
            else {
                nums[x]=v[i];
                x+=2;
            } 
        }
    }
};