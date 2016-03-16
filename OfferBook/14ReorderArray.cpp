#include<iostream>
using namespace std;

void Reorder(int *pData,unsigned int length,bool(*func)(int n));
bool isEven(int n);
/*把所有的奇数都放在偶数的前面*/
void ReorderOddEven(int *pData,unsigned int length)
{
    if(pData==NULL||length<=0)
    {
        return;
    }
    int *pBegin = pData;
    int *pEnd = pData+length-1;
    while(pBegin<pEnd)
    {
        while((pBegin<pEnd)&&(*pBegin&0x1)!=0)
        {
            pBegin++;
        }
        while((pBegin<pEnd)&&(*pEnd&0x1)==0)
        {
            pEnd--;
        }
        if(pBegin<pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}
/***********Function Two********************/
void Reorder(int *pData,unsigned int length,bool (*func)(int n))
{
    if(pData==NULL||length<=0)
    {
        return;
    }
    int *pBegin = pData;
    int *pEnd = pData+length-1;
    while(pBegin<pEnd)
    {
        while((pBegin<pEnd)&&(!func(*pBegin))
        {
            pBegin++;
        }
        while((pBegin<pEnd)&&(*pEnd))
        {
            pEnd--;
        }
        if(pBegin<pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

void ReorderOddEven(int *pData,unsigned int length)
{
    Reorder(pData,length,isEven);
}

bool isEven(int n)
{
    return (n&1)==0;
}

/********Test Function*********/
void PrintArray(int numbers[],int length)
{
    if(numbers==NULL||length<0)
    {
        return;
    }
    for(int i=0;i<length;i++)
    {
        cout<<numbers[i]<<" ";
    }
    cout << endl;
}

void Test(const char *testName,int numbers[],int length)
{
    if(testName!=NULL)
    {
        cout<<testName<<"begins"<<endl;
    }
    int *copy = new int[length];
    for(int i=0;i<length;i++)
    {
        copy[i] = numbers[i];
    }
    PrintArray(numbers,length);
    ReorderOddEven(numbers,length);
    PrintArray(numbers,length);

    delete[] copy;
}

void Test1()
{
    int numbers[] = {1,2,3,4,5,6,7};
    Test("Test1",numbers,sizeof(numbers)/sizeof(int));
}

void Test2()
{
    int numbers[] = {2,4,6,1,3,5,7};
    Test("Test2",numbers,sizeof(numbers)/sizeof(int));
}

void Test3()
{
    int numbers[] = {1,3,5,7,2,4,6};
    Test("Test3",numbers,sizeof(numbers)/sizeof(int));
}

void Test4()
{
    int numbers[] = {1};
    Test("Test4",numbers,sizeof(numbers)/sizeof(int));
}

void Test5()
{
    int numbers[] = {2};
    Test("Test5",numbers,sizeof(numbers)/sizeof(int));
}

void Test6()
{
    Test("Test6",NULL,0);
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    return 0;
}
