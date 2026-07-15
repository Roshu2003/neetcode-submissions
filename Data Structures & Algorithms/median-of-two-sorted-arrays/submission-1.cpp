class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int n = nums1.size();
        int m = nums2.size();
        int lo = 0;
        int hi = n;
        while(lo <= hi){
            int mid = (lo + hi) / 2;

            //partition of nums1
            int px = mid;
            //partition of num2
            int py = (n + m + 1) / 2 - px; // total elemnt which comes in the second array

            int x1 = (px == 0) ? INT_MIN : nums1[px - 1]; // max element of left part in nums1
            int x2 = (py == 0) ? INT_MIN : nums2[py - 1]; // max element of left part in nums2
           
            int x3 = (px == n) ? INT_MAX : nums1[px];     // min ele of right part in nums1;
            int x4 = (py == m) ? INT_MAX : nums2[py];     // min ele of right part in nums2;

            if(x1 <= x4 && x2 <= x3){
                if((n + m) % 2 == 0){
                    return (min(x3,x4) + max(x1,x2)) / 2.0;
                }
                else return max(x1,x2);
            }
            else if(x1 > x4)hi = mid - 1;
            else lo = mid + 1;
        }
        return 0.0;
    }
};
