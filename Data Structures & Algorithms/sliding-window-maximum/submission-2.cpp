class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxH;
        vector<int> res;

        int l = 0;
        int r = k-1;

        for (int i = 0; i < k; i++ ){
            maxH.push({nums[i],i});
            
            
        }
        res.push_back(maxH.top().first);

        while (r < (int)nums.size()-1){

            l++;
            r++;

            maxH.push({nums[r], r});

            while(maxH.top().second < l){
                maxH.pop();
            }

            res.push_back(maxH.top().first);
        }

        return res;




    }
};
