/*
Runtime: 112 ms, faster than 21.09% of C online submissions for Longest Substring Without Repeating Characters.
*/
int lengthOfLongestSubstring(char* s) {
    int MaxCount = 0;
    int TempCount = 1;
    
    int iFront = 0;
    int iLast = iFront + 1;
    int iTemp = iFront;
    
    int isSame = 0;
    
    while(s[iFront] != '\0')
    {
        iTemp = iFront;
        while(iTemp < iLast)
        {
            if(s[iTemp] == s[iLast])
            {
                isSame = 1;
            }
            iTemp ++;
        }
        
        if(!isSame && s[iLast]!= '\0')
        {
            iLast ++;
            TempCount ++;
        }
        else
        {
            if(TempCount > MaxCount)
                MaxCount = TempCount;
            iFront ++;
            iLast = iFront + 1;
            TempCount = 1;
            iTemp = iFront;
            isSame = 0;
        }
    }
    
    return MaxCount;
}
