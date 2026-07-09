class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto i : hand) mp[i]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto i : mp) pq.push(i);
        vector<pair<int,int>> v;
        int cnt = groupSize;
        // bool ok = true;
        while(!pq.empty()){
            int num = pq.top().first;
            int freq = pq.top().second;
            pq.pop();
            
            if (v.size() >= 1 && v.back().first + 1 != num)
            {
                return false;
            }
            else 
            {
                v.push_back({num , freq-1}) ;
            }

            if(v.size() == cnt){
                for(auto i : v)
                {
                    if (i.second >= 1) pq.push(i) ;
                }
                v.clear();
            }
        }
        if (v.size() == 0) return true ;
        else return false ;
        // return true ;
    }
};