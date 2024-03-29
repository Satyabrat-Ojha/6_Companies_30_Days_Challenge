//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    vector<string> ans;
    vector<vector<int>> visited;
    string curr;
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        ans.clear();
        curr.clear();
        visited.assign(n, vector<int>(n, 0));
        solve(0, 0, n, m);
        return ans;
    }
    
    void solve(int i, int j, int n, vector<vector<int>> &m) {
        if(i < 0 || j < 0 || i >= n || j >= n) return;
        if(visited[i][j] || !m[i][j]) return;
        if(i == n - 1 && j == n - 1) {
            ans.push_back(curr);
            return;
        }
        
        visited[i][j] = 1;
        
        curr.push_back('D');
        solve(i + 1, j, n, m);
        curr.pop_back();
        
        curr.push_back('L');
        solve(i, j - 1, n, m);
        curr.pop_back();
        
        curr.push_back('R');
        solve(i, j + 1, n, m);
        curr.pop_back();
        
        curr.push_back('U');
        solve(i - 1, j, n, m);
        curr.pop_back();
        
        visited[i][j] = 0;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends