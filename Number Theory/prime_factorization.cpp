#include <bits/stdc++.h>
int primechk[21000];
int fprime[21000]; 
void preprocess()
{
    int i, j;
    for(i=2 ; i<=20000 ; i++)
    {
        if(primechk[i]==0)
        {
            fprime[i]=i;
            for(j=2 ; i*j<=20000 ; j++)
            {
                primechk[i*j]=1;
                if(fprime[i*j]==1)
                {
                    fprime[i*j]=i;
                }
            }
        }
    }
}


int main()
{
    preprocess();
    int n;
    scanf("%d",&n);
    while(n!=1)
    {
        printf("%d\n",fprime[n]);
        n=n/fprime[n];
    }
}
