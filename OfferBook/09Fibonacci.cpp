#include<iostream>
using namespace std;

/*function one*/
long long fibonacci_1(unsigned int n)
{
    if(n<=0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }

    return fibonacci_1(n-1)+fibonacci_1(n-2);
}
/*function 2*/
long long fibonacci_2(unsigned int n)
{
    int result[2] = {0,1};
    if(n<2)
    {
        return result[n];
    }
    long long fibOne = 1;
    long long fibTwo = 0;
    long long fibN = 0;
    for(unsigned int i=2;i<=n;i++)
    {
        fibN = fibOne + fibTwo;
        fibTwo = fibOne;
        fibOne = fibN;
    }
    return fibN;
}

int main()
{
    unsigned int n = 0;
    long long result = 0;
    cout<<"请输入n的值的大小:"<<endl;
    cin>>n;
    result = fibonacci_2(n);
    cout<<"结果是:"<<result<<endl;
    return 0;
}
