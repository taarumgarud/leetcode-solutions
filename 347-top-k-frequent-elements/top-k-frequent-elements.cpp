class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
        unordered_map<int,int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        auto it = mp.begin();
        for(int cnt = 0; cnt<k && it!=mp.end(); cnt++, it++){
            pq.push({it->second, it->first});
        }

        for(;it!=mp.end(); it++){
            if(it->second>pq.top().first){
                pq.push({it->second,it->first});
                pq.pop();
            }
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};