//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
    vector<pair<char,int>> v;
    v.push_back({src[0],1});
    
    for(int i=1;i<src.size();i++) {
        if(src[i]==src[i-1]) {
            v.back().second++;
        }
        else {
            v.push_back({src[i],1});
        }
    }
    
    string ans = "";
    for(auto e:v) {
        ans+=e.first+to_string(e.second);
    }
    return ans;
}     
 
