class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++;
        priority_queue<pair<int,char>> pq;
        map<char,int> mp;
        for(auto i : tasks) mp[i]++;
        for(auto i : mp) pq.push({i.second,i.first});
        int cnt = 0, ans = 0;
        vector<pair<int,char>> temp;
        while(!pq.empty() || !temp.empty()){
            if(pq.empty()){
                ans += n;
                cnt = 0;
                for(auto i : temp) pq.push({i.first,i.second});
                temp.clear();
            }
            int freq = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            cnt++;
            if(freq > 1) temp.push_back({freq-1,c});
            if(cnt == n){
                ans += n;
                cnt = 0;
                for(auto i : temp) pq.push({i.first,i.second});
                temp.clear();
            }
        }
        ans += cnt;
        return ans;
    }
};

// a -> 3, b -> 3
// 