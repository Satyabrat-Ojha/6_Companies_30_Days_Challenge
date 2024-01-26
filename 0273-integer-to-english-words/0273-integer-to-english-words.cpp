class Solution {
    unordered_map<int,string> word = {
        {1,"One"},
        {2,"Two"},
        {3,"Three"},
        {4,"Four"},
        {5,"Five"},
        {6,"Six"},
        {7,"Seven"},
        {8,"Eight"},
        {9,"Nine"},
    };
    unordered_map<int,string> tens = {
        {2,"Twenty"},
        {3,"Thirty"},
        {4,"Forty"},
        {5,"Fifty"},
        {6,"Sixty"},
        {7,"Seventy"},
        {8,"Eighty"},
        {9,"Ninety"},
    };
    unordered_map<int,string> tens1 = {
        {10,"Ten"},
        {11,"Eleven"},
        {12,"Twelve"},
        {13,"Thirteen"},
        {14,"Fourteen"},
        {15,"Fifteen"},
        {16,"Sixteen"},
        {17,"Seventeen"},
        {18,"Eighteen"},
        {19,"Nineteen"},
    };


public:
    string numberToWords(int num) {
        if(!num) return "Zero";
        
        int n = num;
        int on = n%1000;
        n/=1000;
        int th = n%1000;
        n/=1000;
        int mi = n%1000;
        n/=1000;
        int bi = n;

        string ans="";
        string w,x,y,z;
        w = numbers(bi);
        x = numbers(mi);
        y = numbers(th);
        z = numbers(on);

        if(!w.empty()) ans += w + " Billion ";
        if(!x.empty()) ans += x + " Million ";
        if(!y.empty()) ans += y + " Thousand ";
        if(!z.empty()) ans += z;
        
        if(ans.back() == ' ') ans.pop_back();

        return ans;
    }

    string numbers(int n) {
        if(!n) return "";

        int o = n%100;
        n/=100;
        int h = n;
        
        string ans="";
        if(h) ans = word[h] + " Hundred ";
        if(o) {
            int t = o/10;
            if(t==1) {
                ans += tens1[o];
                return ans;
            }
            if(t) {
                ans += tens[t] + " ";
            }
            if(o%10) {
                ans += word[o%10] + " ";
            }
        }

        ans.pop_back();
        cout<<ans<<" ";
        return ans;
    }
};