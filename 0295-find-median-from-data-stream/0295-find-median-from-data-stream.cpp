class MedianFinder {
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper; 
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        lower.push(num);
        if(lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        }
        if(!upper.empty() && lower.top() > upper.top()) {
            upper.push(lower.top());
            lower.push(upper.top());
            upper.pop();
            lower.pop();
        }
    }
    
    double findMedian() {
        if(upper.size() != lower.size()) return lower.top();
        return ((double) lower.top() + upper.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */