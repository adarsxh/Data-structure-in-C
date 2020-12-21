#include<stdio.h>

void merge(int a[], int l, int m, int h)
	{
		int n1=m-l+1;
		int n2 = h-m;
		int left[n1], right[n2];
		for(int i=0; i<n1;i++)
			left[i]=a[l+i];
		for(int j=0; j<n2; j++)
			right[j]=a[m+1+j];
		int i=0, j=0, k=l;
		while(i<n1&&j<n2){
			if(right[i] <= left[j])
				a[k++]=right[i++];
			else
				a[k++]=left[j++];
		}
		while(i<n1)
			a[k++] = right[i++];
		while(j<n2)
			a[k++] = left[j++];
	}
void mergesort(int a[],int l, int r){
	if(r>l){
		int m = l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}

int main()
{
	int a[] = {10, 15, 20, 40, 8, 11, 16, 22, 25};
	mergesort(a,0,8);
	for(int i=0;i<8;i++){
		printf("%d\t", a[i]);
	}
	}

