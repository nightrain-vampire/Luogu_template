#include<iostream>
#include<cstdio>
#include<set>
#include<string>
#include<memory.h>
using namespace std;

typedef long long ll;

//打题准备
const int maxn=20000;
//char s[maxn];

//hash准备
const int base=131;
//const int mod=141592653;
const ll mod=19260817337;

//hash数组和进制数组
ll myhash[maxn],b[maxn];

//hash函数
void myreset()
{
    memset(myhash,0,sizeof(myhash));
    memset(b,0,sizeof(b));
}

void myset(const string&s)
{
    myhash[0]=0;
    b[0]=1;
    for(int i=1;i<=s.size();i++)
    {
        myhash[i]=(myhash[i-1]*base%mod+s[i-1]-'0')%mod;
        b[i]=(b[i-1]*base)%mod;
    }
}

//string每位标号从1开始
inline ll calhash(int left,int right)
{
    ll res=(myhash[right]-myhash[left-1]*b[right-left+1]%mod+mod)%mod;
    return res;
}

int main()
{
    int N;
    scanf("%d",&N);
    string s;
    set<ll> res;
    for(int i=0;i!=N;i++)
    {
        cin>>s;
        myreset();
        myset(s);
        res.insert(calhash(1,s.size()));
    }
    printf("%d\n",res.size());
    system("pause");
}