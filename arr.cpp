#include<iostream>

using namespace std;
int main(){
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int k=0;
	int j=n-1;
	int x=0;
	while(k<j){
		if(a[k]==a[j]  && a[j]==0)
		{
			k++;	
			
		}
		else if(a[k]==a[j]  && a[j]==1)
		{
			j--;	
			
		}
		
		else if(a[k]==0 && a[j]==1)
		{
			
			k++;
			j--;
		}
		else if(a[k]==1 && a[j]==0){
			
			int temp;
			temp=a[j];
			a[j]=a[k];
			a[k]=temp;
			k++;
			j--;
		}
		x++;
		}
	for(i=0;i<n;i++) 
	{
		cout<<a[i];
	}
	return 0;
 }

