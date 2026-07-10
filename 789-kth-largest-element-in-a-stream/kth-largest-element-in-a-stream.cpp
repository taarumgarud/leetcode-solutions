class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int i = 0; i<nums.size() && i<size; i++){
            pq.push(nums[i]);
        }
        for(int j = size; j<nums.size(); j++){
            if(nums[j]>pq.top()){
                pq.pop();
                pq.push(nums[j]);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<size){
            pq.push(val);
        }
        else if(val>pq.top()){
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */