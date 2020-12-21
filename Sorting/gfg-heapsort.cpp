#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void maxheapify(int a[],int n,int i){
	int largest = i, left = 2*i+1, right = 2*i+2;
	if(left<n&&a[left]>a[largest]) largest = left;
	if(right<n&&a[right]>a[largest]) largest = right;
	if(largest!=i){
		swap(&a[largest],&a[i]);
		maxheapify(a, n,largest);
	}
}
void buildheap(int a[], int n){
	for(int i=(n-2)/2;i>=0;i--)
		maxheapify(a,n,i);
}

void heapsort(int a[],int n){
	buildheap(a, n);
	for(int i=n-1;i>=1;i--){
		swap(&a[0],&a[i]);
		maxheapify(a,i,0);
	}
}

int main(){
	int a[]={10, 15, 50, 4, 20};
	
	heapsort(a,5);
	for(int i;i<5;i++)
		printf("%d\t",a[i]);
}
