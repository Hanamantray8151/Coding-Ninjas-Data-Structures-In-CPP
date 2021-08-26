//O(n^2).
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = 0;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum = sum + nums[j];
                if(sum > maxsum){
                    maxsum = sum;
                }
            }
        }
        return maxsum;
    }
};

//O(n).
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0];
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
            if(sum > maxsum){
                maxsum = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return maxsum;
    }
};
