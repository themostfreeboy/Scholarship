#include<conio.h>
#include<stdio.h>
void exchange(int x[],int a,int b)
{
    int t;
    t=x[a];
    x[a]=x[b];
    x[b]=t;
}
main()
{
      FILE *p1,*p2;
      p1=fopen("scholar.in","r");
      p2=fopen("scholar.out","w");
      int n,i,j,max,t;
      fscanf(p1,"%d",&n);
      int y[n+1],s[n+1],w[n+1],sum[n+1],num[n+1];
      for(i=1;i<=n;i++)
      {
                       fscanf(p1,"%d",&y[i]);
                       fscanf(p1,"%d",&s[i]);
                       fscanf(p1,"%d",&w[i]);
                       num[i]=i;
                       sum[i]=y[i]+s[i]+w[i];
      }
      for(i=1;i<=n;i++)
      {
                      t=i;
                      for(j=i+1;j<=n;j++)
                      {
                                        if(sum[j]>sum[t])   t=j;
                                        else if(sum[j]==sum[t]&&y[j]>y[t])   t=j;
                                        else if(sum[j]==sum[t]&&y[j]==y[t]&&num[j]<num[t])   t=j;
                      }
                      exchange(sum,t,i);
                      exchange(num,t,i);
      }
      for(i=1;i<=5;i++)
                fprintf(p2,"%d %d\n",num[i],sum[i]);
}
