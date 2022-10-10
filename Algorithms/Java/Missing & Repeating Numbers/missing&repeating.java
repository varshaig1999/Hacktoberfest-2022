import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution {

    public static int[] missingAndRepeating(ArrayList<Integer> arr, int n) {
        // Write your code here
        int rsum=0,sum=0,r=0,m=0;
        Collections.sort(arr);
        
        for(int i=0;i<n;i++)
        {
            rsum+=(i+1);
            sum+=arr.get(i);
            if(i>0 && arr.get(i)==arr.get(i-1))
                r=arr.get(i);
        }
        if(rsum>sum)
            m=r+(rsum-sum);
        else
            m=r-(sum-rsum);
        int rarr[]={m,r};
        return rarr;
    }
}
