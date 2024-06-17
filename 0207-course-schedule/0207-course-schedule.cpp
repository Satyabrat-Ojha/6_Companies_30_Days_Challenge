class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> parent(n, 1), vis(n), V(n);
        vector<vector<int>> adj(n);
        
        for(auto prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            parent[prerequisite[0]] = 0;
        }

        for(int i=0;i<n;i++)
            if(parent[i] && !dfs(i, vis, V, adj)) return false;

        for(int i=0;i<n;i++) {
            if(!V[i]) return false;
        }

        return true;
    }

    bool dfs(int i, vector<bool>& vis, vector<bool>& parent, vector<vector<int>>& adj) {
        if(vis[i]) return false;
        if(parent[i]) return true;
        vis[i] = 1;
        parent[i] = 1;

        for(auto e : adj[i]) {
            if(!dfs(e, vis, parent, adj)) 
                return false;
        }

        vis[i] = 0;
        return true;
    }
};