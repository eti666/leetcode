/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// this solution in test case used 44 ms.
int* twoSum(int* nums, int numsSize, int target) {
    
    for(int i=0; i<numsSize; i++)
    {
        // as we know, we just test the second number(which index j) just
        // after the first number(which index j).
        for(int j = i+1; j < numsSize; j++)
        {
            if(nums[j] == (target-nums[i])) 
            {
                // found. return.
                int *index = (int *)malloc(2 * sizeof(int));
                index[0] = i;
                index[1] = j;
                return index;
            }
        }
    }
    // not found, return NULL.
    return NULL;
}
