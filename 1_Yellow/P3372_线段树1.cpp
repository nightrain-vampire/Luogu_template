#include <iostream>
#include <cstdio>

#define init long long
using namespace std;
init n,m;

//lt:懒惰标记，代表区间每点应该加的数
struct node
{
    init l,r,data;
    init lt;    
}tree[1000010];
init arr[1000010];

//建树
void build(init l,init r,init index,init arr[])
{
    tree[index].lt=0;
    tree[index].l=l;
    tree[index].r=r;
    if(l==r)
    {
        tree[index].data=arr[l];
        return ;
    }
    init mid=(l+r)/2;
    build(l,mid,index*2,arr);
    build(mid+1,r,index*2+1,arr);
    tree[index].data=tree[index*2].data+tree[index*2+1].data;
    return ;
}
//懒惰标记刷新
void push_down(init index)
{
    if(tree[index].lt!=0)
    {
        tree[index*2].lt+=tree[index].lt;
        tree[index*2+1].lt+=tree[index].lt;
        init mid=(tree[index].l+tree[index].r)/2;
        tree[index*2].data+=tree[index].lt*(mid-tree[index*2].l+1);
        tree[index*2+1].data+=tree[index].lt*(tree[index*2+1].r-mid);
        tree[index].lt=0;
    }
    return ;
}
//更新区间的值
void up_data(init index,init l,init r,init k)
{
    if(tree[index].r<=r && tree[index].l>=l)
    {
        tree[index].data+=k*(tree[index].r-tree[index].l+1);
        tree[index].lt+=k;
        return ;
    }
    push_down(index);
    if(tree[index*2].r>=l)
        up_data(index*2,l,r,k);
    if(tree[index*2+1].l<=r)
        up_data(index*2+1,l,r,k);
    tree[index].data=tree[index*2].data+tree[index*2+1].data;
    return ;
}
//区间搜索
init search(init index,init l,init r)
{
    if(tree[index].l>=l && tree[index].r<=r)
        return tree[index].data;
    push_down(index);
    init num=0;
    if(tree[index*2].r>=l)
        num+=search(index*2,l,r);
    if(tree[index*2+1].l<=r)
        num+=search(index*2+1,l,r);
    return num;
}

//refer:https://www.cnblogs.com/jason2003/p/9676729.html
int main()
{
    cin>>n>>m;
    for(init i=1;i<=n;i++)
        cin>>arr[i];
    build(1,n,1,arr);
    for(init i=1;i<=m;i++)
    {
        init f;
        cin>>f;
        if(f==1)
        {
            init a,b,c;
            cin>>a>>b>>c;
            up_data(1,a,b,c);
        }
        if(f==2)
        {
            init a,b;
            cin>>a>>b;
            printf("%lld\n",search(1,a,b));
        }
    }
}