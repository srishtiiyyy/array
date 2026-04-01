import java.util.*;
class superior{
    public static int func(int[]arr,int n){
        int maxi=Integer.MIN_VALUE;
        int cnt=0;
        for(int i=arr.length-1;i>=0;i--){
            if(arr[i]>maxi){
                cnt++;
                maxi=arr[i];
            }
        }
        return cnt;
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println(func(arr,n));
        sc.close();

    }
}