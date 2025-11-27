import java.util.*;

/*
Question 1: Edward’s Birthday

Problem Statement:
Edward has a circular cake. He wants to find the maximum number of pieces 
he can get by making exactly N straight vertical cuts on the cake.

Your task:
Write a function that returns the maximum number of pieces that can be 
obtained by making N number of cuts.

Note:
Since the result can be very large, return the result modulo 1000000007.

Input:
An integer N (number of cuts)

Output:
Maximum number of pieces after N cuts.

Formula:
Maximum pieces = (N * (N + 1)) / 2 + 1

Example:
Input: 1 → Output: 2
Input: 5 → Output: 16
*/

public class edwardbirthday {

    static final int MOD = 1000000007;

    public static int cakemax(int N) {
        long n = N;
        long pieces = (n * (n + 1)) / 2 + 1;
        return (int)(pieces % MOD);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        System.out.println(cakemax(N));
        sc.close();
    }
}
