class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        // Pair position with speed so we can sort them together
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sort cars by position descending (closest to target first)
        sort(cars.rbegin(), cars.rend());

        stack<double> fleetTimes;
        for (auto& car : cars) {
            double currentTime = car.second;
            
            // If the current car takes MORE time than the fleet in front,
            // it cannot catch up. It starts a NEW fleet.
            if (fleetTimes.empty() || currentTime > fleetTimes.top()) {
                fleetTimes.push(currentTime);
            }
            // If currentTime <= fleetTimes.top(), it catches up and 
            // becomes part of the existing fleet. We do nothing.
        }

        return fleetTimes.size();
    }
};
