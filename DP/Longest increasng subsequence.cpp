#include<iostream>
using namespace std;

int LIS(int arr[], int n){					//O(n^2) solution
	int lis[n];
	lis[0] = 1;
	for(int i=1;i<n;i++){
		lis[i]=1;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i])
				lis[i] = max(lis[i], lis[j]+1);
		}
	}
	int res = lis[0];
	for(int i=0;i<n;i++)
		res = max(res,lis[i]);
	return res;
}

int ceilindex(int tail[],int l, int r, int x){
	while(r>l){
		int m = l+ (r-l)/2;
		if(tail[m]>=x)
			r=m;
		else
			l = m+1;
	}
	return r;
}

int liseff(int arr[], int n){ 				//O(nlogn) solution
	int tail[n],len=1;
	for(int i=1;i<n;i++){
		if(arr[i]>tail[len-1]){
			tail[len] = arr[i];
			len++;
		}
		else{
			int c = ceilindex(tail,0,len-1,arr[i]);
			tail[c] = arr[i];
		}
	}
	return len+1;
}

int main(){
	int arr[]={8,100,150,10,12,14,110};
	cout<<"Tabulation: "<<LIS(arr, 7)<<endl;
	cout<<"Efficient: "<<liseff(arr, 7)<<endl;
}
