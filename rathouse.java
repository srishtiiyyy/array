//⭐ PROBLEM SUMMARY

// You are given:

// r = number of rats

// unit = food each rat eats

// arr[] = food available in each house

// n = number of houses

// You must find:

// 👉 Minimum number of houses from the start needed to collect enough food for all rats.

// ⭐ STEP 1 → Total Food Required

// Total food needed =

// total_food_required = r * unit
import java.util.*;
public class rathouse{
public static int func(int n,int arr[],int r,int unit){
    if(arr==null || n==0)return -1;
    int required=r*unit;
    int collected=0;
    for(int i=0;i<n;i++){
      collected+=arr[i];
      if(collected>=required){
        return i+1;
      }
}
return 0;
}
public static void main(String[]args){
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int[]arr=new int[n];
    for(int i=0;i<n;i++){
        arr[i]=sc.nextInt();
    }
    int unit=sc.nextInt();
    int r=sc.nextInt();
    System.out.println(func(n,arr,r,unit));
     sc.close();
}
}