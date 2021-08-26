//O(n * log n) + O(n).
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] == nums[i + 1]){
                return nums[i];
            }
        }
        return -1;
    }
};

//O(n).
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mapuse;
        for(int i=0;i<nums.size();i++){
            mapuse[nums[i]]++;
        }
        for(auto m : mapuse){
            if(m.second > 1){
                return m.first;
            }
        }
        return -1;
    }
};
