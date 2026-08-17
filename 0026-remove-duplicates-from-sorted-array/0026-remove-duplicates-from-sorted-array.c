int removeDuplicates(int* nums, int numsSize) {
    int k=1;
    if (numsSize==0){return 0;}
    for(int i=0;i<numsSize-1 ;i++){
        if(nums[i] != nums[i+1]){
            nums[k]=nums[i+1];
            k++;
        }
    }
    return k;
}