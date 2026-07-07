/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwaps(vector<int>& nums){
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i = 0; i<n; i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<bool> vis(n,false);
        int swaps = 0;

        for(int i = 0; i<n; i++){
            if(vis[i] || v[i].second==i){
                continue;
            }
            int cycle = 0;
            int j = i;

            while(!vis[j]){
                vis[j] = true;
                j = v[j].second;
                cycle++;
            }
            swaps+=cycle-1;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            vector<int> level;
            for(int i = 0; i < s; i++){
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
            ans+=minSwaps(level);
        }
        return ans;
    }
};