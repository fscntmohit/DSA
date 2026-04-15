class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for(int i : nums){
            while(i){
                int a = i%10;
                i /= 10;
                if(a == digit){
                    ans++;
                }
            }
        }
        return ans;
    }
};
