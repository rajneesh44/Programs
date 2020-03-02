//implementing Least Recently Used implementation 

#include<iostream>
using namespace std;
#include<conio.h>

int main(){
		
		int no_of_pages,no_of_frames,pages[20],i,fault_count=0;
        cout<<"\n\tEnter the No. of pagess:";
        cin>>no_of_pages;  //Store the no of pagess
        cout<<"\n\t Enter the Reference String:";

        for(i=0;i<no_of_pages;i++)
        {
	        cout<<"\t";
	        cin>>pages[i]; //Store the pagess
        }
     
        cout<<"\n\t Enter the No of frames:-";
        cin>>no_of_frames;
        
        int frame[no_of_frames],index_count[no_of_frames];

        for(i=0;i<no_of_frames;i++)
        {
        frame[i]=-1; //Store the frames
        index_count[i]=0; //Track when the pages is last used
        }
        i=0;

        while(i<no_of_pages)
        {
          int j=0,flag=0;
          while(j<no_of_frames)
          {
          	//Check if pages already exists in frames or not
             if(pages[i]==frame[j]){  
             flag=1;
             index_count[j]=i+1;
             }
             j++;
          }   
          j=0;  
          cout<<"\n\t- - - - - - - - - - - - - - - - - - - \n";
          cout<<"\t |"<<" "<<pages[i]<<"-->";   
          if(flag==0)
          {
        	int min=0,k=0;
        	
            while(k<no_of_frames-1)       
              {
                  if(index_count[min]>index_count[k+1]) //Calculating the pages which is least recently used
                  min=k+1;
                k++;
              }
             frame[min]=pages[i]; //Replacing it
             index_count[min]=i+1;    //Increasing the time
             fault_count++;           //fault_counting pages Fault
                  
          	while(j<no_of_frames)
          	{
            	cout<<"\t|"<<frame[j]<<"|";
            	j++;
          	}         
          	cout<<"\t |";
          }
         i++;           
        }
        cout<<"\n\t- - - - - - - - - - - - - - - - - - - \n";
        cout<<"\n\tpages Fault is:"<<fault_count;
        getch();
        return 0;
}   
