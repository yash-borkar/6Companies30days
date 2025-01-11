// https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        vector<int> v;
        for(int i=1; i<arr.size()-1; i++){
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) v.push_back(i);
        }

        int ans = 0;
        for(int i=0; i<v.size(); i++){
            int j = v[i]-1;
            int k = v[i]+1;
            int count = 0;
            while(j>=0){
                if(arr[j] >= arr[j+1]) break;
                count++;
                j--;
            }
            while(k<=arr.size()-1){
                if(arr[k] >= arr[k-1]) break;
                count++;
                k++;
            }
            ans = max(ans, count+1);
        } 
        return ans;
    }
};