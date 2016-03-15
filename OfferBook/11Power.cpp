#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/*数值的整数次方
1:考虑底数是否为零的问题
2:考虑指数是否为负数的问题
3:考虑可能会出错误的问题
*/
bool InvalidInput = false;
bool equal(double num1,double num2);
double PowerWithUnsignedExponent(double base,unsigned int exponent);
void Test(double base,int exponent,double expectedResult,bool expectedFlag);
double Power(double base,int exponent)
{
    InvalidInput = false;
    if(equal(base,0.0)&&exponent<0)
    {
        InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)exponent;
    if(exponent < 0)
    {
        absExponent = (unsigned int)(-exponent);
    }
    double result = PowerWithUnsignedExponent(base,absExponent);
    if(exponent < 0)
    {
        result = 1.0/result;
    }
    return result;
}

/*method one*/
double PowerWithUnsignedExponentOne(double base,unsigned int exponent)
{
    double result = 1.0;
    for(int i=1;i<=exponent;i++)
    {
        result*=base;
    }
    return result;
}

/*method two*/
double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
    if(exponent==0)
    {
        return 1;
    }
    if(exponent==1)
    {
        return base;
    }
    double result = PowerWithUnsignedExponent(base,exponent>>1);
    result *= result;
    if((exponent&0x1)==1)
    {
        result = result*base;
    }
    return result;
}

bool equal(double num1,double num2)
{
    if((num1-num2)>-0.0000001&&(num1-num2)<0.0000001)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*==============测试代码===============*/
void Test(double base,int exponent,double expectedResult,bool expectedFlag)
{
    double result = Power(base,exponent);
    if(abs(result - expectedResult)<0.0000001&&InvalidInput==expectedFlag)
    {
        printf("Test Passed \n");
    }
    else
    {
        printf("Test Failed \n");
    }
}

int main()
{
    /*底数和指数都为正*/
    printf("Test1 begin.\n");
    Test(2,3,8,false);
    /*底数为负,指数为正*/
    printf("Test2 begin.\n");
    Test(-2,3,-8,false);
    /*底数为正,指数为负*/
    printf("Test3 begin.\n");
    Test(2,-3,0.125,false);
    /*指数为零*/
    printf("Test4 begin.\n");
    Test(2,0,1,false);
    /*底数和指数都为零*/
    printf("Test5 begin.\n");
    Test(0,0,1,false);
    /*底数为零,指数为整数*/
    printf("Test6 begin.\n");
    Test(0,4,0,false);
    /*底数为零,指数为负数*/
    printf("Test6 begin.\n");
    Test(0,-4,0,true);
    return 0;
}
