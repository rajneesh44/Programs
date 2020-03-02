#include<iostream>
using namespace std;
#include<conio.h>

int main(){



        int nop,nof,page[20],i,count=0;

        cout<<"\n\tEnter the No. of Pages:";

        cin>>nop;  //Store the no of Pages

        cout<<"\n\t Enter the Reference String:";

        for(i=0;i<nop;i++)

        {

        cout<<"\t";

        cin>>page[i]; //Store the pages

        }

         

        cout<<"\n\t Enter the No of frames:-";

        cin>>nof;

        int frame[nof],fcount[nof];

        for(i=0;i<nof;i++)

        {

        frame[i]=-1; //Store the frames

        fcount[i]=0; //Track when the page is last used

        }

        i=0;

        while(i<nop)

        {

          int j=0,flag=0;

          while(j<nof)

          {

             if(page[i]==frame[j]){  //Checking whether page already exist in frames or not

             flag=1;

             fcount[j]=i+1;

             }

             j++;

          }   

          j=0;  

          cout<<"\n\t**************************************\n";

          cout<<"\t"<<page[i]<<"-->";   

          if(flag==0)

          {

           int min=0,k=0;

            while(k<nof-1)

              {

                

                if(fcount[min]>fcount[k+1]) //Calculating the page which is least recently used

                  min=k+1;

                k++;

              }

             frame[min]=page[i]; //Replacing it

             fcount[min]=i+1;    //Increasing the time

             count++;           //counting Page Fault

           

          

          while(j<nof)

          {

             cout<<"\t|"<<frame[j]<<"|";

             j++;

          }

           

           }

         i++; 

           

        }

        cout<<"\n\t**************************************\n";

        cout<<"\n\tPage Fault is:"<<count;

        getch();

        return 0;

}   