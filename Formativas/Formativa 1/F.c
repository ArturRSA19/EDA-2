#include <stdio.h>

#define MAXN 100010
#define MAXM 100010

int n,m;
long long int r[MAXN];

int busca_binaria(long long int val);

int main()
{
    long long int resp=0;

	scanf("%d %d",&n, &m);

	for(int i=1;i<=n;i++)	
	{
		scanf("%lld",&r[i]);
		r[i]=r[i]*r[i];
	}

	
	for(int i=1;i<=m;i++)	
	{	
		long long int x,y;
		scanf("%lld %lld",&x,&y);
		resp+=busca_binaria(x*x+y*y);
	}

	printf("%lld\n",resp);
	
	return 0;
}

int busca_binaria(long long int val){
    int ini = 1;
    int fim = n;
    int meio;

    if(val > r[n]){
        return 0;
    }

    while(ini < fim){
        meio = (ini + fim)/2;

        if(r[meio] >= val){
            fim = meio;
        }else{
            ini = meio + 1;
        }
    }
    return n + 1 - fim;
}
