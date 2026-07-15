class Solution {
public:
    int getSum(int a, int b) {
        //110 111
        //1001
        while(b){
            int c = (a & b) << 1;
            a ^= b;
            b = c;
        }
        return a;
    }
};
