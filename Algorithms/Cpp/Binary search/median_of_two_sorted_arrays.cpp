//👉 PROBLEM ON BINARY SEARCH -

// 🎯PROBLEM NAME - MEDIAN OF TWO SORTED ARRAYS


// 📌 PROBLEM STATEMENT ->
/* 
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

   double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
          if (nums1.size() > nums2.size())
          {
              return findMedianSortedArrays(nums2, nums1);
          } 
        
        int x = nums1.size();
        int y = nums2.size();
        
        int start = 0;
        // int end = x ? x < y : y;
        int end = x;

  while (start <= end)
  {
    int partitionX = (start + end) / 2;
    int partitionY = ((x + y + 1) / 2) - partitionX;

    // partitionX  = 0 it means nothing on left side then use INT_MIN
    // partitionX = x it means nothing on right side use INT_MAX

    int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
    int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

    int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
    int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

    if (maxLeftX <= minRightY && maxLeftY <= minRightX)
    {
      // we got the median
      if ((x + y) % 2 == 0)
      {
        return double(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
      }
      else
      {
        return max(maxLeftX, maxLeftY);
      }
    }

    else if (maxLeftX > minRightY) //  we are too far on right side for partitionX, Go on left side
    {
      end = partitionX - 1;
    }

    else // we are too far on left side for partitionX, Go on right side
    {
      start = partitionX + 1;
    }
    }
        return 1;
    }
