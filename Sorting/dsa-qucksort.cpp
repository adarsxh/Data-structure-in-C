#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a=*b;
	*b=temp;
}

int partition(int a[], int l, int h){
	int pivot = a[l];
	int i=l-1, j=h+1;
	while(1){
		do{i++;
		}while(a[i]<pivot);
		do{j--;
		}while(a[j]>pivot);
		if(i>=j)
			return j;
		swap(&a[i],&a[j]);
	}
}
void qsorth(int a[], int l, int h){
	if(l<h){
		int p = partition(a, l, h);
		qsorth(a,l,p);
		qsorth(a,p+1,h);
	}
}

int main(){
	int a[]={8,4,7,9,3,10,5};
	qsorth(a,0,6);
	for(int i=0;i<7;i++)
		printf("%d\t",a[i]);
	
}
