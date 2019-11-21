#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
//int sort(int Scores1[])
//{
//	int i,n=0;
//	
//		for(i=0;i<8;i++){
//			if(Scores1[i]>n)
//			{
//				n=Scores1[i];
//			}	
//		}
//		int temp10=n;
//		n=0;
//		for(i=0;i<8;i++){
//			if(Scores1[i]>n && Scores1[i]<=temp) 
//			{
//				n=Scores1[i];
//			
//			}	
//		}
//		int temp11=n;
//		n=0;
//		for(i=0;i<8;i++){
//			if(Scores1[i]>n && Scores1[i]<=temp) 
//			{
//				n=Scores1[i];
//			
//			}	
//		}
//		int temp12=n;
//	
//	}
//	return n;	
//
//}



int main()
{
	srand(time(NULL));
	char Score1[8]={'A','B','C','D','E','F','G','H'};
	char Score2[8]={'I','J','K','L','M','N','O','P'};
	int Scores1[8]={0,0,0,0,0,0,0,0};
	int Scores2[8]={0,0,0,0,0,0,0,0};
	

	for(int i=0;i<8;i++)
	{
		for(int j=i;j<8;j++)
		{
			if(Score1[i]==j)
			{
				continue;
			}	
			else
			{
				int temp=rand();
				if(temp%2==0)
					Scores1[i]+=1;
				
				else{
					Scores1[j]+=1;
				}
				
							
			}
	}
}
	for(int i=0;i<8;i++)
	{
		for(int j=i;j<8;j++)
		{
			if(Score2[i]==j)
			{
				continue;
			}	
			else
			{
				int temp=rand();
				if(temp%2==0)
					Scores2[i]+=1;
				
				else{
					Scores2[j]+=1;
				}
				
							
			}
	}
}
	cout<<"League Stage"<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<Score1[i]<<"-------";
		cout<<Scores1[i]<<"	"<<endl;
		
		
	}
	cout<<endl<<"----------------------------"<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<Score2[i]<<"-------";
		cout<<Scores2[i]<<"	"<<endl;
		
	}
	cout<<endl<<"________________________________________________________________"<<endl;
	cout<<"Quarter Final stage"<<endl;
//	int res=sort(Scores1);
//	cout<<res;


