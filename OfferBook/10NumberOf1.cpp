#include<iostream>
using namespace std;
/*二进制中1的个数*/

/*function one*/
//循环次数太多
int NumberOf1_1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(n&flag)
        {
            count ++;
        }
        flag = flag<<1;
    }
    return count;
}

/*function two*/
int NumberOf1_2(int n)
{
    int count = 0;
    while(n)
    {
        count ++;
        n = (n-1)&n;
    }
    return count;
}

int main()
{
    int n = 0;
    int m = 0;
    cout<<"请你输入一个二进制数:"<<endl;
    cin>>n;
    m = NumberOf1_2(n);
    cout<<"二进制数中1的个数是:"<<m<<endl;
    return 0;
}
