//Time COmplexity : O(n) it takes two pass.
//Space Complexity : O(1).
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                zeroCount++;
            }else if(nums[i] == 1){
                oneCount++;
            }else if(nums[i] == 2){
                twoCount++;
            }
        }
        nums.clear();
        for(int i=0;i<zeroCount;i++){
            nums.push_back(0);
        }
        for(int j=0;j<oneCount;j++){
            nums.push_back(1);
        }
        for(int k=0;k<twoCount;k++){
            nums.push_back(2);
        }
    }
};

//Time Complexity : O(n) it takes only one pass.
//Space Complexity : O(1).
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int mid = 0;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }else if (nums[mid] == 1){
                mid++;
            }else if(nums[mid] == 2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
