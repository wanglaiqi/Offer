��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�
class Solution {
public:
    int Fibonacci(int n) {
		int A[n+1],i;
		A[0] = 0��
		A[1] = 1;
		for(i=2;i<=n;i++)
		{
			A[i] = A[i-1]+A[i-2];
		}
		
		return A[n];
	}
}