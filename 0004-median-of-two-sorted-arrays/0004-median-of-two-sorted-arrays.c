double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *combined= (int*)malloc((nums1Size+nums2Size) * sizeof(int));
    memcpy(combined,nums1,nums1Size*sizeof(int));
    memcpy(combined+nums1Size,nums2,nums2Size*sizeof(int));
    int total_size;
    total_size=nums1Size+nums2Size;
    int i=0,j=0;
    for (i=0;i<total_size;i++){
        for (j=i+1;j<total_size;j++){
            if (combined[i]>combined[j]){
                int temp=combined[i];
                combined[i]=combined[j];
                combined[j]=temp;
            
            }
            
        }
    }
    double median;
    if (total_size %2 !=0){
        median=combined[(total_size)/2];
        return median;
    }
    else if (total_size %2 ==0){
        median=((double)combined[(total_size -1 ) /2 ] + (double)combined[total_size/2]) /2;
        return median;
    }
    free(combined);
    return 0;
}