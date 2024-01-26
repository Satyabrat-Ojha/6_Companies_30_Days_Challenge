class ThroneInheritance {
    int it;
    map<string,int> id;
    vector<string> name;
    vector<vector<int>> children;
    vector<int> dead;
public:
    ThroneInheritance(string kingName) {
        id[kingName] = 0;
        name.push_back(kingName);
        it=1;
        children.resize(1e5+1);
        dead.resize(1e5+1);
    }
    
    void birth(string parentName, string childName) {
        int ip = id[parentName];
        int ic = id[childName] = it++;
        name.push_back(childName);
        children[ip].push_back(ic);
    }
    
    void death(string name) {
        int i = id[name];
        dead[i]=1;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        dfs(0,ans);
        return ans;
    }

    void dfs(int i, vector<string>& ans) {
        if(!dead[i])
            ans.push_back(name[i]);

        for(auto e:children[i])
            dfs(e,ans);
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */