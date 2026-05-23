class Solution {
    public boolean check(int[] nums) {
        int pivot=-1;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i]>nums[i+1])pivot=i;
        }
        if(pivot==-1)return true;
        int[] arr = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            arr[i]=nums[(i+pivot+1)%nums.length];
        }
         for(int i=0;i<nums.length-1;i++){
            if(arr[i]>arr[i+1])return false;
        }
        return true;
    }
}