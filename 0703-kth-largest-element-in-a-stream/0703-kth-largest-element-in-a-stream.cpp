class KthLargest {
    int n;
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto num:nums) pq.push(num);
        while(pq.size() > n) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > n) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */