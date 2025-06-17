class Solution {
public:
    struct bigger{
        bool operator() (const pair<int, int> a, const pair<int, int> b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /* Record the frequency*/
        unordered_map<int, int> frequency;
        for(int i : nums)
            frequency[i]++;
        /* Define priority queue*/
        priority_queue<pair<int,int>, vector<pair<int,int>>, bigger> q;
        /* Sort the <element, frequency> based on frequency*/
        for(pair<int, int> i:frequency){
            q.push(i);
            if(q.size() > k)
                q.pop();
        }
        /* Output result in vector */
        vector<int> result;
        while(q.size()){
            result.push_back(q.top().first);
            q.pop();
        }
        return result;
        
    }
};