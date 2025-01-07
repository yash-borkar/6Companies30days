// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;  // pair<val, index>
        vector<int>ans;

        //process first window
        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
        }

        //store ans of first window
        ans.push_back(pq.top().first);

        //process remaining window
        for(int i=k; i<nums.size(); i++){
            pq.push({nums[i], i});

            while(pq.top().second <= i-k){
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }
        return ans;
    }
};