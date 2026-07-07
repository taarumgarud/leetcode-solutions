class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mp(26,0) ;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]-'a']++;
        }

        for(int i = 0; i<t.size(); i++){
            mp[t[i]-'a']--;
        }
        int sum = 0;
        for(auto it: mp){
            sum += abs(it);
        }
        return sum;
    }
};