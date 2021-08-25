//O(n^3).
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = 0;
                for(int k=i;k<j;k++){
                    sum = sum + nums[k];
                }
                if(sum > maxsum){
                    maxsum = sum;
                }
            }
        }
        return maxsum;
    }
};

//
