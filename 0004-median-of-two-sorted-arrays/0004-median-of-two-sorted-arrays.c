double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *combined= (int*)malloc((nums1Size+nums2Size) * sizeof(int));
    memcpy(combined,nums1,nums1Size*sizeof(int));
    memcpy(combined+nums1Size,nums2,nums2Size*sizeof(int));
    int total_size;
    total_size=nums1Size+nums2Size;
    int i = 0; // Pointer for nums1
    int j = 0; // Pointer for nums2
    int k = 0; // Pointer for combined array

    // 1. Loop through both arrays until one runs out of numbers
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            combined[k] = nums1[i];
            i++; // Move nums1 pointer forward
        } else {
            combined[k] = nums2[j];
            j++; // Move nums2 pointer forward
        }
        k++; // Move combined pointer forward
    }

    // 2. Clean up leftovers from nums1 (if any)
    while (i < nums1Size) {
        combined[k] = nums1[i];
        i++;
        k++;
    }

    // 3. Clean up leftovers from nums2 (if any)
    while (j < nums2Size) {
        combined[k] = nums2[j];
        j++;
        k++;
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