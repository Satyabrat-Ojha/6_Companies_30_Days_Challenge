//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        for(int i=0;i<n;i++) {
            int x = abs(arr[i]);
            x--;
            arr[x]*=-1;
        }
        
        vector<int>a;
        
        for(int i=0;i<n;i++) {
            if(arr[i]>0) a.push_back(i+1);
        }
        
        for(int i=0;i<n;i++) {
            if(a[1]==abs(arr[i])) {
                swap(a[0],a[1]);
                break;
            }
        }

        return a;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends