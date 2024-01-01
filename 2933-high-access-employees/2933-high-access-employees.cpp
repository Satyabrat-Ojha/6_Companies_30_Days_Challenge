class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        sort(access_times.begin(),access_times.end());
        
        for(int i=2 ; i<access_times.size() ; i++)
            if(access_times[i-2][0] == access_times[i][0])
                if(withinOneHour(access_times[i-2][1],access_times[i][1]))
                    if(ans.empty() || ans.back() != access_times[i][0])
                        ans.push_back(access_times[i][0]);

        return ans;
    }

    bool withinOneHour(string a, string b) {
        int x = stoi(a.substr(0,2));
        x++;
        string s = to_string(x);
        if(s.size()<2) s = "0"+s;

        s = s + a[2] + a[3];

        return s>b;
    }
};