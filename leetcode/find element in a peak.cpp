class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==2){
            if(nums[0]>nums[1])
                return 0;
            else
                return 1;
        }
        int ini=0,fin=nums.size()-1,mtd=0;
        while(ini<fin){
            mtd=(ini+fin)/2;
           // cout<<mtd<<" ";
            if(mtd>0 && nums[mtd+1]<nums[mtd] && nums[mtd-1]<nums[mtd]){
               //  cout<<"\n";
                 return mtd;
            }
            else if(mtd<nums.size() && nums[mtd]>nums[mtd+1]){
                 fin=mtd;
            }
            else{
                 ini=mtd+1;
            }
        }
       //    cout<<"\n";
        if(nums[nums.size()-1]>nums[0]){
            return nums.size()-1;
        }
        else{
            return 0;
        }
    }
};
