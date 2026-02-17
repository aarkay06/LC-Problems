class Solution {
public:
    bool isValid(vector<int>& dist, double hour, int speed) {
        double time = 0;
        for (int i = 0; i < dist.size(); i++) {
            if (i != dist.size() - 1) {
                time += ceil((double)dist[i] / (double)speed);
            } else {
                  time += (double)dist[i] / (double)speed;
            }
        }
        return time <= hour;
    }
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int min = 1;
        int max = 1e7;
        int speed = -1;
        while (min <= max)
        {
            int mid = (min + max) / 2;
            if (isValid(dist, hour, mid))
            {
                max = mid - 1;
                speed = mid;
            }
            else
            {
                min = mid + 1;
            }
        }
        return speed;
    }
};