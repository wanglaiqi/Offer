#include<iostream>
#include<stdio.h>
using namespace std;

unsigned int findFirstBitIs1(int num);
bool IsBit(int num,unsigned int indexBit);
/*找出数组中只出现一次的数字*/
void findNumberAppearanceOnce(int data[],int length,int *num1,int *num2)
{
    if(data==NULL||length<0)
    {
        return;
    }
    int resultExecuteOr = 0;
    for(int i = 0;i<length;i++)
    {
        resultExecuteOr^=data[i];
    }
    unsigned int indexOf1 = findFirstBitIs1(resultExecuteOr);
    *num1 = 0;
    *num2 = 0;
    for(int j = 0;j<length;j++)
    {
        if(IsBit(data[j],indexOf1))
        {
            *num1^=data[j];
        }
        else
        {
            *num2^=data[j];
        }
    }
}

/*返回第一位是1的下标*/
unsigned int findFirstBitIs1(int num)
{
    int indexBit = 0;
    while(((num&1) == 0)&&(indexBit < 8*sizeof(int)))
    {
        indexBit++;
        num = num>>1;
    }
    return indexBit;
}

//找到num从右边数第一位是1的位置
bool IsBit(int num,unsigned int indexBit)
{
    num = num>>indexBit;
    return (num&1);
}

/*测试代码*/
void Test(const char *testName,int data[],int length,int expected1,int expected2)
{
    if(testName!=NULL)
    {
        printf("%s begins:",testName);
    }
    int result1,result2;
    findNumberAppearanceOnce(data,length,&result1,&result2);

    if((expected1==result1&&expected2==result2)||(expected2==result1&&expected1==result2))
    {
        printf("Passed.\n\n");
    }
    else
    {
        printf("Failed.\n\n");
    }

}

void Test1()
{
    int data[] = {2,4,3,6,3,2,5,5};
    Test("Test1",data,sizeof(data)/sizeof(int),4,6);
}

void Test2()
{
    int data[] = {4,6};
    Test("Test2",data,sizeof(data)/sizeof(int),4,6);
}

void Test3()
{
    int data[] = {4,6,1,1,1,1};
    Test("Test3",data,sizeof(data)/sizeof(int),4,6);
}
int main()
{
    Test1();
    Test2();
    Test3();
    return 0;
}
