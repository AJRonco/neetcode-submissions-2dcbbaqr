class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        if (arr.size() == 1 ){
            return 1;
        }
        
        int R = 1;
        int L = 0;
        int res = 0;
        int curNum = arr[0];
        bool less = false;
        bool greater = false;

        for ( R; R < arr.size(); R++){
            //printf("Left %d Right %d\n", L, R);
            if (arr[R] > curNum){
                if (greater){
                    //printf("greater DUP %d, %d\n", curNum, arr[R]);
                    res = max(res, R - L);
                    L = R - 1;
                    greater = true;
                    less = false;
                    
                }
                else {
                    less = false;
                    greater = true;
                    
                }
                
            }
            else if (arr[R] < curNum){
                if (less){
                    //printf("less DUP %d, %d\n", curNum, arr[R]);
                    res = max(res, R - L );
                    L = R - 1;
                    less = true;
                    greater = false;
                }
                else {
                    less = true;
                    greater = false;
                    
                }
            }

            else {
                //printf("ELSE (should be equal) %d, %d\n", curNum, arr[R]);
                
                res = max(res, R - L );
                L = R;
                less = false;
                greater = false;
            }
            curNum = arr[R];
            


        }
        
        res = max(res, R - L);
        return res;
    }
};