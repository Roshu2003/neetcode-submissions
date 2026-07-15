class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++){
            int l = i + 1;
            int r = numbers.size() - 1;
            int sum = target - numbers[i];
            while(l <= r){
                int mid = (l + r)/2;
                if(numbers[mid] == sum){
                    return {i + 1,mid + 1};
                }
                else if(numbers[mid] > sum){
                    r = mid  - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return {-1,-1};
    }
};
