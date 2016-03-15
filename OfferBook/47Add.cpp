#include<iostream>
using namespace std;

/*不适用加减乘除做加法运算*/
int add(int num1,int num2)
{
    int sum = 0;
    int carray = 0;
    do
    {
        sum = num1^num2;
        carray = (num1&num2)<<1;

        num1 = sum;
        num2 = carray;
    }
    while(num2!=0);
    return num1;
}

/*测试代码*/
void Test(int num1,int num2,int expected)
{
    int result = add(num1,num2);
    if(result = expected)
    {
        cout<<num1<<"+"<<num2<<"="<<result<<"passed"<<endl;
    }
    else
    {
        cout<<num1<<"+"<<num2<<"="<<result<<"Failed"<<endl;
    }
}
int main()
{
    Test(1,2,3);
    Test(111,899,1010);
    Test(3,0,3);
    Test(-2,-8,-10);
    return 0;
}
