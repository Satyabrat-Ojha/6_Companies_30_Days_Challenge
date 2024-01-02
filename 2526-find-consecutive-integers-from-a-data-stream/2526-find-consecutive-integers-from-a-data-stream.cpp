class DataStream {
    int val,n,i;

public:
    DataStream(int value, int k) {
        val=value;
        n=k;
        i=0;
    }
    
    bool consec(int num) {
        if(num==val) {
            i++;
            if(i>=n) return 1;
            return 0;
        }
        i=0;
        return 0;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */