大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
class Solution {
public:
    int Fibonacci(int n) {
		int A[n+1],i;
		A[0] = 0；
		A[1] = 1;
		for(i=2;i<=n;i++)
		{
			A[i] = A[i-1]+A[i-2];
		}
		
		return A[n];
	}
}