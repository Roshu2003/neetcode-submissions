class Solution {
public://6 / 4 = 1 % 4 = 2
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n = v.size();
        int m = v[0].size();
        int l = 0;
        int r = n * m - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            int rr = mid / m;
            int c = mid % m;
            int x = v[rr][c];
            if(x == t)return true;
            if(x < t)l++;
            else r--;
        }
        return false;
    }
};
