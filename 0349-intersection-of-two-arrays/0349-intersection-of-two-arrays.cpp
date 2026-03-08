class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0;i<n;i++){
            int element = nums1[i];
            bool alreadyPresent = false;
            for(int k = 0; k < ans.size(); k++){
                if(ans[k] == element){
                    alreadyPresent = true;
                    break;
                }
            }
            if(alreadyPresent) continue;
            for(int j=0;j<m;j++){
                if(element == nums2[j]){
                ans.push_back(element);
               nums2[j] = -2;
               break;
                }  
            }
        }
        return ans;
        
    }
};