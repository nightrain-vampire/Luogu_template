#include<iostream>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;

const int maxn=1e6+7;
int a[maxn];

int n,k;

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i!=n;i++)
    {
        scanf("%d",&a[i]);
    }

    vector<int> ans_max,ans_min;
    deque<int> find_max,find_min;

    //区间最大，维护单调递减队列
    //区间最小，维护单调递增队列
    //队列中存储元素索引
    for(int i=0;i!=n;i++)
    {
        while(!find_max.empty()&&a[i]>a[find_max.back()])
        {
            find_max.pop_back();
        }

        while(!find_min.empty()&&a[i]<a[find_min.back()])
        {
            find_min.pop_back();
        }
        
        find_max.push_back(i);
        find_min.push_back(i);

        //区间长度符合规定，可以开始处理了
        if(i>=k-1)
        {
            //当队列中放了明显不在同一区间的元素
            while(!find_max.empty()&&i-find_max.front()+1>k)
            {
                find_max.pop_front();
            }
            while(!find_min.empty()&&i-find_min.front()+1>k)
            {
                find_min.pop_front();
            }
            ans_max.push_back(a[find_max.front()]);
            ans_min.push_back(a[find_min.front()]);
        }
    }

    for(int i=0;i!=ans_min.size();i++)
    {
        printf("%d ",ans_min[i]);
    }
    printf("\n");
    for(int i=0;i!=ans_max.size();i++)
    {
        printf("%d ",ans_max[i]);
    }
    printf("\n");

    system("pause");
}