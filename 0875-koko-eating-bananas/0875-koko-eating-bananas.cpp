class Solution {
public:

    bool isPossible(vector<int>& piles, int h, int mid) {

        long long hours = 0;

        for(int i = 0; i < piles.size(); i++) {

            int pile = piles[i];

            // ceil(pile / mid)
            hours += (pile + mid - 1) / mid;

            if(hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = e;

        while(s <= e) {

            int mid = s + (e - s) / 2;

            if(isPossible(piles, h, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }

        return ans;
    }
};