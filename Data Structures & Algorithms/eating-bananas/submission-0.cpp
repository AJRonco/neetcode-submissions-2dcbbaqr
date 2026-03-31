class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = std::ranges::max(piles);
        int min = 1;
        
        int finalK = max;


        while (min <= max) {
            int mid = min + (max - min) /2;
            long long res = calculateK(piles, mid);

            if (res <= h) {
                max = mid-1;
                finalK = mid;
            }
                
           else {
                min = mid+1;
           }
            
        


        }
        return finalK;
    }

    long long calculateK(std::vector<int>& piles, int k) {
        long long totalTime = 0;
        for (auto pile: piles) {
            totalTime += (pile + k -1)/k;
        }
        return totalTime;

    }
};
