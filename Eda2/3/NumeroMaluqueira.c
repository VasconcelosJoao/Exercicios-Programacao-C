#include<stdio.h>
#include<stdlib.h>

int _Tam;

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

typedef long int item;

void merge(item *V,  int l,  int m,  int r)
{
item *R=malloc(sizeof(item)*(r-l+1));
 int i=l,j=m+1,k=0;
while(i<=m && j<=r)
{
if(less(V[i],V[j]))
    R[k++]=V[i++];
else
    if(V[i]==V[j])
    {
        j++;
        _Tam--;
    }
    else
    R[k++]=V[j++];
}
while(i<=m)
    R[k++]=V[i++];
while(j<=r)
    R[k++]=V[j++];
k=0;

for(i=l;i<=r;i++)
    V[i]=R[k++];
free(R);
}

void mergesort(item *V, int l, int r)
{
if (l>= r) return;
int meio=(l+r)/2;
mergesort(V,l,meio);
mergesort(V,meio+1,r);
merge(V,l,meio,r);
}



int main(int argc, char const *argv[])
{
int N;
item *x=malloc(sizeof(item)*132000);
scanf("%d",&N);
_Tam=N;
for (int i=0;i<N;i++)
    scanf("%ld",&x[i]); 
mergesort(x,0,_Tam-1);
if(_Tam%2!=0)
    x[_Tam++]=1000000000;
int num=_Tam/2;
int add[num];
for(int i=0;i<num;i++) 
    x[_Tam++]=x[i*2]+x[(i*2)+1];
mergesort(x,0,_Tam-1);

for(int i=0;i<_Tam;i+=4)
    printf("%ld\n",x[i]);


// for (int i=0;i<_Tam;i++)
//     printf("%d ",x[i]);
printf("Elemento: %d\n",_Tam);
    
    return 0;
}
