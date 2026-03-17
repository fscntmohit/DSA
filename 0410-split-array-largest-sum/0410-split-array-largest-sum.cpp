class Solution {
public:

    // Function to check if array can be split into <= m parts
    // such that largest subarray sum <= mid
    bool isPossible(vector<int>& arr, int n, int m, int mid) {

        int studentCount = 1;
        int pageSum = 0;

        for(int i = 0; i < n; i++) {

            // If single element > mid, impossible
            if(arr[i] > mid)
                return false;

            if(pageSum + arr[i] <= mid) {
                pageSum += arr[i];
            }
            else {
                studentCount++;
                pageSum = arr[i];

                if(studentCount > m)
                    return false;
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int m) {

        int n = nums.size();
        int sum = 0;

        for(int i = 0; i < n; i++)
            sum += nums[i];
    // Binary Search Range
    // Minimum possible answer = largest book
        int s = *max_element(nums.begin(), nums.end());
        int e = sum;

        int ans = -1;

        while(s <= e) {

            int mid = s + (e - s) / 2;

            if(isPossible(nums, n, m, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                // If not possible, increase allowed pages
                s = mid + 1;
            }
        }

        return ans;
    }
};