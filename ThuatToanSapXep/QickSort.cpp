
#include<stdio.h>
#include<conio.h>

int part(int a[],int l,int r);
void quick_sort(int a[],int l,int r);
void swap(int a[],int b[]);
void quick_sort(int a[],int l,int r)
{
  if(r>l)
     {  int k;
	k= part(a,l,r);
	quick_sort(a,l,k-1);
	quick_sort(a,k+1,r);
     }
}
int part(int a[],int l,int r)
{
	  int ls,t,k;
	  k=(l+ r)/2;
	  swap(&a[l],&a[k]);
	  ls=l;
	  while((a[ls+1]<=a[l])&&(ls<r))
	  {
		  ls++;
	  }
	  t=ls+1;
	  while((a[l]<a[t])&&(t<r))
	  {
		  t++;
	  }
	  while(t<=r)
	  {
		  if(a[t]<a[l])
		  {
			  swap(&a[ls+1],&a[t]);
			  ls++;
		  }
		  t++;
	  }
	  swap(&a[l],&a[ls]);
	  k=ls;
	return k;
}

void swap(int a[],int b[])
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
main()
{

 int a[20],r,i,l=1;
 printf("nhap so phan tu cua mang a: n=");
 scanf("%d",&r);
 
 for(i=1;i<=r;i++)
 {
   printf("a[%d]=",i);
   scanf("%d",&a[i]);
 }
 quick_sort(a,l,r);
 printf("cac phan tu cua mang a sau khi sap xep:");
 for(i=1;i<=r;i++)
 {
   printf("%5d",a[i]);
 }
 getch();
}


