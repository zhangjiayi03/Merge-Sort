#include <stdio.h>
#include <stdlib.h>

void Merge(int a[],int b[],int first,int mid,int last)  //�ϲ�������������
{
    int p=first,q=mid+1;
    int pos=first;
    while(p<=mid&&q<=last)
    {
        if(a[p]<a[q])
        {
            b[pos++]=a[p++];
        }
        else
        {
            b[pos++]=a[q++];
        }
    }
    if(p>mid)
    {
        while(q<=last)
        {
            b[pos++]=a[q++];
        }
    }
    else
    {
        while(p<=mid)
        {
            b[pos++]=a[p++];
        }
    }
}
void MergePass(int a[],int b[],int gap,int n) //��һ���Ĳ��������ݽ��кϲ�
{
    int i=0;
    int j;
    while(i<=n-2*gap+1)
    {
        Merge(a,b,i,i+gap-1,i+2*gap-1);
        i=i+2*gap;
    }
    if(i<(n-gap))
        Merge(a,b,i,i+gap-1,n-1);
    else
        for(j=i;j<n;j++)
            b[j]=a[j];
}
void Merge_sort(int a[],int b[],int n)  //�鲢����ķǵݹ�  ���Ҳ����л�д
{
    int gap=1;
    while(gap<n)
    {
        MergePass(a,b,gap,n);
        gap=2*gap;
        MergePass(b,a,gap,n);
        gap=2*gap;
    }
}
int main()
{
    int data[20]={8,7,2,6,9,10,3,4,5,1,345,2342,15,64,67,135,16,4,6,24};
    int cp[20],i;
    Merge_sort(data,cp,20);
    for(i=0;i<=19;i++)
        printf("%d\n",data[i]);
    return 0;
}
