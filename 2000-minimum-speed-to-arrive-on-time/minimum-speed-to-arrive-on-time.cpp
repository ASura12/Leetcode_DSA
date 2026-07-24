class Solution {
public:
    bool canReach(vector<int>& dist, double hour, int speed) {
        double time = 0.0;

        // All trains except the last
        for (int i = 0; i < dist.size() - 1; i++) {
            time += (dist[i] + speed - 1) / speed;
        }

        // Last train
        time += (double)dist.back() / speed;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        // Impossible to arrive on time
        if (hour <= dist.size() - 1)
            return -1;

        int low = 1;
        int high = 10000000;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canReach(dist, hour, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};