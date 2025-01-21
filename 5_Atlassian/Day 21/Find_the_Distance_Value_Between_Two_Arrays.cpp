// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int ans = 0;
        int dist;
        for(int i=0; i<n; i++){
            bool flag = true;
            for(int j=0; j<m; j++ ){
                dist = abs(arr1[i] - arr2[j]);
                if(dist <= d){
                    flag = false;
                    break;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};