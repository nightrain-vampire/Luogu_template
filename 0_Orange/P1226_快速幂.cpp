#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;

ll k;

ll quick_pow(ll b,ll p)
{
    ll res=1;
    for(;p>0;p>>=1)
    {
        if(p&1)
        {
            res=res*b%k;
        }
        b=b*b%k;
    }
    return (res%k);
    //最后还要mod一下，防止1^0 mod 1这种坑比情况
}

int main()
{
    ll b,p;
    scanf("%lld%lld%lld",&b,&p,&k);
    printf("%lld^%lld mod %lld=%lld",b,p,k,quick_pow(b,p));
    system("pause");
}