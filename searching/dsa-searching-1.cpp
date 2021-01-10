#include<bits/stdc++.h>
using namespace std;

int bsearch(int a[],int n, int x){
	int high = n-1, low=0;
	while(low<=high){
		int mid = (low+high)/2;
		if(a[mid]==x)
			return mid;
		else if(a[mid]>x)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}

int main(){
	int a[] = {2, 3, 45, 56, 67, 78, 89};
	printf("%d",bsearch(a,7,7));
	
}
