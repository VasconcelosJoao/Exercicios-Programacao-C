#include<stdio.h>
#include<stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

typedef int item;

void merge(item *V, int l, int m, int r)
{
  item *R=malloc(sizeof(item)*(r-l+1));
  int i=l,j=m+1,k=0;

  while(i<=m && j<=r)
  {
    if(lesseq(V[i],V[j]))
      R[k++]=V[i++];
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

void mergesort(item *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}


void printFunc(item *v,int code,int N){
    int menor=0,maior=N-1,medio;
        while(menor<=maior){
            medio =(maior+menor)/2;
            if(v[medio]==code)
            {
                printf("sim\n");
                return;
            }
            else if(v[medio]>code)
            {
                maior = medio - 1;
            }
            else
            {
                menor = medio + 1;
            }
        }
        printf("nao\n");
}


int main(int argc, char const *argv[])
{
    int N;
    scanf("%d",&N);
    item itens[140000];
    for(int i=0;i<N;i++)
        scanf("%d",&itens[i]);
    mergesort(itens,0,N-1);

    int I[140000],c=0;
    while(scanf("%d",&I[c])==1)
        c++;

    for (int i = 0; i < c; i++)
    {
        printFunc(itens,I[i],N);
    }
    
    return 0;
}
