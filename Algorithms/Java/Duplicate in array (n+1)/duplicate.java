import java.util.* ;
import java.io.*; 
import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution{
    public static int findDuplicate(ArrayList<Integer> arr, int n){
        // Write your code here.
        HashSet<Integer> s=new HashSet();
        int elem=0;
        for(int i=0;i<n;i++)
        {
            if(s.contains(arr.get(i)))
            {
                elem=arr.get(i);
                break;
            }
            else
                s.add(arr.get(i));
        }
        return elem;
    }
}
