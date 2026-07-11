class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end(), greater<int>());
        sort(g.begin(),g.end(), greater<int>());
        int i = 0, j = 0;
        while(i<g.size() && j<s.size()){
            if(s[j]>=g[i]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j;
    }
};