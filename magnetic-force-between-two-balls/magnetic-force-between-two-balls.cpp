class Solution {
public:
    bool isValid(vector<int>& position, int balls, int targetForce) {
        int placedBalls = 1; 
        int lastPlaced = position[0];
        
        for(int i = 1; i < position.size(); i++) {
            if(position[i] - lastPlaced >= targetForce) {
                placedBalls++;
                lastPlaced = position[i];
                
                if(placedBalls == balls) {
                    return true;
                }
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int minForce = 1; 
        int maxForce = position.back() - position[0]; 
        int bestForce = 0; 

        while(minForce <= maxForce) {
            int targetForce = minForce + (maxForce - minForce) / 2; 
            
            if(isValid(position, m, targetForce)) {
                bestForce = targetForce; 
                minForce = targetForce + 1;
            } else {
                maxForce = targetForce - 1;
            }
        }
        
        return bestForce;
    }
};