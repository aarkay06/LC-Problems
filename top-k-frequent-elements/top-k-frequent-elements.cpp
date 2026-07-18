class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
              mp[nums[i]]++;
        }

       priority_queue<pair<int, int>> q;
        for(auto& el  : mp){
            q.push({el.second, el.first});
        }
        

        vector<int> res;
        while(k){
            pair<int, int> p = q.top();
            q.pop();
            res.push_back(p.second);
            k--;
        }
        return res;
    }
};