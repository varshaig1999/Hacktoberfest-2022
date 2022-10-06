import java.util.*; 

class mostFrequent{ 
  
public static void main (String[] args) { 
    
  Scanner sc = new Scanner(System.in);
      System.out.println("Enter the size of the array :");
      int size1 = sc.nextInt();
      int[] arrayEx1 = new int[size1];
      System.out.println("Enter the elements of the array:");
      
      
      for(int i=0; i<arrayEx1.length; i++) {
         arrayEx1[i] = sc.nextInt();
      }
    
    Arrays.sort(arrayEx1); 
    int n=arrayEx1.length;
    
    int countofmax = 1;
    int temp = arrayEx1[0]; 
    int count = 1; 
    
    for (int i = 1; i < arrayEx1.length; i++) 
    { 
      if (arrayEx1[i] == arrayEx1[i - 1]) 
        count++; 
      else
      { 
        if (count > countofmax) 
        { 
          countofmax = count; 
          temp = arrayEx1[i - 1]; 
        } 
        count = 1; 
      } 
    } 
  
   
    if (count > countofmax) 
    { 
      countofmax = count; 
      temp = arrayEx1[n - 1]; 
    } 
  System.out.println("The number which occured highest time is:"+temp); 
  } 
} 