#include<iostream>

using namespace std;

int PrintBrackets(int i,int j,int size,int *bracket,char &matrix)
{
	
	if(i==j)
	{	cout<< matrix++;
		return 0;
	}
	
	cout<<"(";
	
	PrintBrackets( i , *((bracket+i*size)+j) , size , bracket , matrix);
	PrintBrackets( *((bracket+i*size)+j)+1, j , size ,bracket , matrix);
	
	cout<<")";
	return 0;
}

int main(void)
{
	int n;
	cout<<"Enter the number of matrices"<<endl;
	cin>>n;
	int size=n+1;
	int arr[size];
	cout<<"Enter the order in such a way that row of the next matrix is equal to the column of the former matrix"<<endl;
	for(int x=0;x<size;x++){
		cin>>arr[x];
	}
	for(int x=0;x<size;x++){
		cout<<arr[x]<<" ";
	}
	
//	int arr[]= {40,20,30,10,30};
//	int size=sizeof(arr)/sizeof(arr[0]);
	
	int m[size][size]={0};
	int bracket[size][size]={0};
	int j,min,q;
	for(int d=1;d<size-1;d++){
		for(int i=1;i<size-d;i++)
		{
			j=i+d;
			min=1000000;
			for(int k=i;k<=j-1;k++)
			{	q=m[i][k]+m[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
				if(q<min)
				{	min=q;
					bracket[i][j]=k;
					
				}
			}
			m[i][j]=min;
cout<<"\n \n";                 //printing basic matrix
	for(int i=1;i<size;i++){
		for(int j=1;j<size;j++){
			cout<<m[i][j]<<"     ";
		}
		cout<<"\n";
	}
				
		}
	}
	cout<<"\n \n";                 //printing basic matrix
	for(int i=1;i<size;i++){
		for(int j=1;j<size;j++){
			cout<<m[i][j]<<"     ";
		}
		cout<<"\n";
	}
	
	cout<<"\n \n";                     //printing brackets matrix
	for(int i=1;i<size;i++){
		for(int j=1;j<size;j++){
			cout<<bracket[i][j]<<"   ";
		}
		cout<<"\n";
	}
	
	char matrix = 'A';
	cout<<"\n";
	cout<<"The order of the matrices for the minimum cost is : ";
	PrintBrackets(1, size-1 , size , (int *)bracket , matrix);
	cout<<"\n";
	cout<<"Minimum cost of multiplication of these matrices is: "<<m[1][size-1];
}
