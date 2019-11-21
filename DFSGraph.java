import java.util.LinkedList;
import java.util.*;

public class DFSGraph
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		// int V = 5;
		int i=0; 
		int V =sc.nextInt();

        Graph graph = new Graph(V); 
        while(i<(V+4)){
        	int num1=sc.nextInt();int num2=sc.nextInt();

        	graph.AddEdge(graph,num1,num2);
        	i++;
        }

        // graph.AddEdge(graph, 0, 1); 
        // graph.AddEdge(graph, 0, 4); 
        // graph.AddEdge(graph, 1, 2); 
        // graph.AddEdge(graph, 1, 3); 
        // graph.AddEdge(graph, 1, 4); 
        // graph.AddEdge(graph, 2, 3); 
        // graph.AddEdge(graph, 3, 4); 
  
        graph.PrintGraph(graph); 
        System.out.println("Enter the start node");
        int num = sc.nextInt();
        System.out.print("DFS of this graph is :   ");
        graph.DFSRun(graph,num,V);
        System.out.println();
        System.out.print("BFS of this graph is:    ");
        graph.BFSRun(graph,num,V);
	}
}

 class Graph
{
	private int V;
	private LinkedList<Integer> adj[];

	public Graph(int V)                             //constructor for object creation
	{
		this.V=V;
		adj = new LinkedList[V];

		for(int i=0;i<V;i++)
		{
			adj[i]= new LinkedList<Integer>();
		}
	}
	public void AddEdge(Graph graph , int source , int dest)
	{
		graph.adj[source].add(dest);
		graph.adj[dest].add(source);
	}
	
	public void PrintGraph(Graph graph)
	{
		for(int v=0;v<graph.V;v++)
		{
			System.out.println("Adjacency list of vertex "+ v);
			System.out.print("head");
			for(int x: graph.adj[v])
			{ 
                System.out.print(" -> "+x); 
             }
            System.out.println("\n");
		}
	}

	public void makeDFS( int v, boolean visited[])
	{
		visited[v]= true;
		System.out.print(v+" ");
		Iterator<Integer> i = adj[v].listIterator();

		while(i.hasNext())
		{
			int n = i.next();
			if(!visited[n])
				makeDFS(n,visited);
		}
	}

	public void DFSRun(Graph graph, int v,int V)
	 {
	 	boolean visited[]= new boolean[V];
	 	makeDFS(v,visited);
	 }
	 
	 public void BFSRun(Graph graph, int v,int V)
	 {
	 	boolean visited[]= new boolean[V];
	 	makeBFS(v,visited);
	 }

    public void makeBFS(int v, boolean visited[])
	 {
	 	LinkedList<Integer> temp = new LinkedList();
	 	visited[v] = true;
	 	temp.add(v);

	 	while( temp.size()!=0 ) 
	 	{
	 		v=temp.poll();
	 		System.out.print(v+" ");
	 		Iterator<Integer> i = adj[v].listIterator();
	 		while(i.hasNext())
	 		{
	 			int n = i.next();
	 			if(!visited[n])
	 			{
	 				visited[n]=true;
	 				temp.add(n);
	 			}
	 		}
		}
	 }
}
