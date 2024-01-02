//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        int c=0;
        S+='I';
        vector<int> a(S.size());
        
        for(int i=0;i<S.size();i++) {
            if(S[i]=='I') {
                a[i]=++c;
                int it = i-1;
                while(it>=0 && a[it]==0) {
                    a[it--] = ++c;
                }
            }
        }
        
        string s="";
        for(auto e:a) {
            s+=to_string(e);
        }
        return s;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends