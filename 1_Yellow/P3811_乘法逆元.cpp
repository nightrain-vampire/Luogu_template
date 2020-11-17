#include<iostream>
#include<cstdio>
typedef long long ll;

int n,p;
const int maxn=3e6+7;
int inv[maxn];

//此题要求1~n的逆元，直接快速幂和拓展欧几里得会死
//应该线性求逆元
//refer：https://oi-wiki.org/math/inverse/

int main()
{
    scanf("%d%d",&n,&p);
    inv[1]=1;
    for(int i=2;i<=n;i++)
    {
        inv[i]=(ll)(p-p/i)*inv[p%i]%p;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",inv[i]);
    }
    system("pause");
}