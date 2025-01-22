// https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int ans=0;
        int i=0,j=0;
        int n=g.size();
        int m=s.size();
        while(i<n && j<m){
            if(s[j]>=g[i]){
                ans++;
                i++; 
            }
            j++;

        }
        return ans;
    }
};