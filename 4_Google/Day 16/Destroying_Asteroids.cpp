// https://leetcode.com/problems/destroying-asteroids/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long planetMass = mass;
        sort(asteroids.begin(), asteroids.end());
        for(int i=0; i<asteroids.size(); i++){
            if(planetMass >= asteroids[i]) planetMass += asteroids[i];
            else return false;
        }
        return true;
    }
};