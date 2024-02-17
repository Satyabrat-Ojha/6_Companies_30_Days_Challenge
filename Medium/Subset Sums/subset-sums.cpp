//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        rec(0, ans, 0, arr, N);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
    void rec(int sum, vector<int>& ans, int idx, vector<int>& a, int n) {
        if(idx == n) {
            ans.push_back(sum);
            return;
        }
        
        rec(sum, ans, idx+1, a, n);
        rec(sum+a[idx], ans, idx+1, a, n);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends