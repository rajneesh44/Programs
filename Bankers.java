import java.util.*;
import java.io.*;
import java.lang.*;

class Bankers
{
	public static void main(String[] args)
	{
		int np,nr,i,c,e;
		System.out.println("Write the number of processes and number of resources: ");
		Scanner sc = new Scanner(System.in);
		np = sc.nextInt();
		nr = sc.nextInt();
		
		int[][] allocated = new int[np][nr];
		int[][] maximum = new int[np][nr];
		int[][] need = new int[np][nr];
		int[] available = new int[nr];
		int[] alloc_avail = new int[nr];
		
		System.out.println("Fill the resource allocated matrix: ");
		for(i=0;i<np;i++) for(c=0;c<nr;c++) allocated[i][c] = sc.nextInt();
		
		System.out.println("Fill the maximum resources availability matrix:  ");
		for(i=0;i<np;i++) for(c=0;c<nr;c++) maximum[i][c] = sc.nextInt();	
		
		System.out.println("Fill the availability matrix of resources: ");
		for(i=0;i<nr;i++) available[i] = sc.nextInt();
		
		System.out.println("The remaining need matrix is: ");
	//calculating the remaining need matrix suing maximum and allocated matrix 
		for(i=0;i<np;i++)
		{
			for(c=0;c<nr;c++)
			{
				need[i][c] = maximum[i][c] - allocated[i][c];
				System.out.print(need[i][c]+" ");
			}
			System.out.println();
		}
		
		for(i=0;i<nr;i++)
		{
			for(c=0;c<np;c++)
			{
				alloc_avail[i]+=allocated[c][i];
			}
			alloc_avail[i]+=available[i];
		}
		
		int[] process_complete = new int[np];
		int[] unsafe_chk = new int[np];
		int tnp = np,ip=0,f=0;
		
		for(i=0;i<np;i++)
		{
			for(c=0;c<nr;c++)
			{
				if(alloc_avail[c]<need[i][c]) 
				{
					f=1;
					System.out.println("Unsafe");
				}
			}
		}
		if(f==0){
		while(true)
		{
			f=0;
			if(ip==np) ip=0;
			if(unsafe_chk[ip]==1 && tnp<=1)
			{
				f=1;
				break;
			}
			if(process_complete[ip] == 1) 
			{
				ip++;
				continue;
			}
			else
			{
				for(c=0;c<nr;c++)
				{
					if(available[c]<need[ip][c]) f=1;
				}
				if(f==1) 
				{
					for(c=0;c<nr;c++)
					{
						if(alloc_avail[c]<need[ip][c]) unsafe_chk[ip]=1;
					}
					ip++;
					continue;
				}
				else
				{
					process_complete[ip]=1;
					System.out.println("Process "+ip+" can be allocated the resources..");
					System.out.println("Process Terminated. Releasing resources..");
					System.out.println("The resources available after release are:");
					for(c=0;c<nr;c++)
					{
						available[c] += allocated[ip][c];
						System.out.print(available[c]+" ");
					}
					System.out.println();
					ip++;
					tnp--;
					if(tnp==0) break;
				}
			}
		}
		}
		if(tnp==0) System.out.println("Safe");
		//else if(f==1) System.out.println("Unsafe");
	}
}