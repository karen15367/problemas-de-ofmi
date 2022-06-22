class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%2==1){
            n++;
        }
        return nums[n/2-1];
    }
};
