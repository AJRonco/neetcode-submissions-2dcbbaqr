class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        if (k > arr.size()){
            return 0;
        }
        int L = 0;
        int res = 0;
        

        for (int R = k; R < arr.size()+1; R++){

            int curAvg = 0;
            for (int temp = L; temp < R; temp++){
                curAvg = curAvg + arr[temp];
                printf("%d ", arr[temp]);
            }
            printf("\n");
            curAvg = curAvg / k;

            if (curAvg >= threshold){
                res++;
            }
            L++;
            
        }
        return res;
    }
};