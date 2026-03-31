class Solution {
public:
    int trap(vector<int>& height) {

    int L = 0;
    int R = height.size()-1;
    int lMax = 0;
    int rMax = 0;
    int cLevel = 0;
    
    int res = 0;


    while (L < R ){

        if (height[L] > lMax){
            lMax = height[L];
        }
        if (height[R] > rMax){
            rMax = height[R]; 
        }

        int fill = min(lMax, rMax);

        if (fill > cLevel){
            
            cLevel = fill;
            for(int i = L; i < R; i++){

                if (height[i] <= fill) {
                    res+= fill - height[i];
                    height[i] = fill;
                }
            }
        }

        if (lMax > rMax){
            R--;
        }
        else {
            L++;
        }



    }
    return res;
        
    }
};
