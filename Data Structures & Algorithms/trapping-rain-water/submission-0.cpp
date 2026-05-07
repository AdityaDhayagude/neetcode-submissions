class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        vector<int>gOnL(n), gOnR(n);
        int maxOnL = INT_MIN; int maxOnR = INT_MIN;


        for(int i=0;i<n; i++){
            maxOnL = max(maxOnL,height[i]);
            maxOnR = max(maxOnR, height[n-i-1]);

            gOnL[i] = maxOnL;
            gOnR[n-i-1] = maxOnR;
        }

        int totalWater = 0;

        for(int i=0; i<n; i++){
            int waterLevel = min(gOnL[i], gOnR[i]);

            totalWater+= (waterLevel-height[i]);

        }

        return totalWater;

    }
};
