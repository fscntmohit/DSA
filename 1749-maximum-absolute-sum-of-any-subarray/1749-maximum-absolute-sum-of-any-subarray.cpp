class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n= nums.size();
        int maxEnding=0, minEnding=0;
        int maxSum=0, minSum=0;
        for(int i = 0;i<n;i++){
            maxEnding = max(nums[i],maxEnding+nums[i]);
            maxSum = max(maxSum,maxEnding);
            minEnding = min(nums[i],minEnding+nums[i]);
            minSum = min(minSum,minEnding);
        }
        return max(maxSum, abs(minSum));
        
    }
};