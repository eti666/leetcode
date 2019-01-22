/* Runtime: 20 ms, faster than 100.00% of C online submissions for Median of Two Sorted Arrays. */
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int iNums1 = 0;
    int iNums2 = 0;
    int iVNums = 0; // virual array
    
    int Count = nums1Size + nums2Size;
    int iHalf = Count / 2;
    
    int HalfNum = 0;
    int preHalfNum = 0;
    // iVNums not add in for but in anyone case for if
    for(; ((iVNums < Count)&&(iVNums <= iHalf)); )
    {
        if(iNums1 < nums1Size && iNums2 < nums2Size)
        {
            // all can move
            if(nums1[iNums1] < nums2[iNums2])
            {
                printf("case-1\n");
                preHalfNum = HalfNum;
                HalfNum = nums1[iNums1];
                
                iNums1 ++; 
            }
            else
            {
                preHalfNum = HalfNum;
                HalfNum = nums2[iNums2];
                
                iNums2 ++;
            }
            iVNums ++;
        }
        else if(iNums1 >= nums1Size && iNums2<nums2Size)
        {
            // just nums2 can move
            preHalfNum = HalfNum;
            HalfNum = nums2[iNums2];
            
            iNums2++;
            iVNums ++;
        }
        else
        {
            // just nums1 can move
            printf("case-4\n");
            preHalfNum = HalfNum;
            HalfNum = nums1[iNums1];
            
            iNums1++;
            iVNums++;
        }
    }
    if(Count%2==0)
    {
        // mid
        return (double)(preHalfNum + HalfNum)/2;
    }
    else
        return HalfNum;
    return 0;
}
