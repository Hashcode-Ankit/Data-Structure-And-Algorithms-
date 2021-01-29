#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

/// Only for directed graph
void add(vector<int> arr[],int indegree[],int v,int u)
{
	arr[v].push_back(u);
	indegree[u]++;
}

                            /* BFS approach for the graph*/
void BFS(vector<int> arr[],bool visited[],int source)
{
	queue<int> q;
	q.push(source);
	visited[source]=true;
	while(q.empty()==false)
	{
		int u= q.front();
		q.pop();
		cout<<u<<" ";
        for(int x :arr[u])
        {
          if(visited[x]==false)
          {
          	visited[x]=true;
          	q.push(x);
          }
        }
	}

}
void BFS_disconnected(vector<int> arr[], int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}

	for(int i=0;i<v;i++)
	{
     if(visited[i]==false)
     {
     	BFS(arr,visited,i);
     }
	}
}

                                    /*  DFS approach for graph */
void Dfs(vector<int> arr[],bool visited[],int source)
{
	visited[source]=true;
	cout<<source<<" ";
	for(int x: arr[source])
	{
		if(visited[x]==false)
		Dfs(arr,visited,x);
	}

}
void DFS(vector<int> arr[],int v)
{
  bool visited[v];
  for(int i=0;i<v;i++)
  {
  	visited[i]=false;
  }
  for(int i=0;i<v;i++)
  {
  	if(visited[i]==false)
  	Dfs(arr,visited,i);	
  }
  
}   

///kansh's algorithm
void topological(vector<int> arr[],int indegree[],int v)
{
   queue<int> q;
   for(int i=0;i<v;i++)
   {
   	if(indegree[i]==0)
   	{
   		q.push(i);
   	}
   }
   while(q.empty()==false)
   {
   	int u=q.front();
   	q.pop();
   	cout<<u<<" ";
   	for(int x: arr[u])
   	{
   		indegree[x]--;
   		if(indegree[x]==0)
   		{
   			q.push(x);
   		}
   	}
   }
}
///////////////////////check for loop using topological or kansh algo/////////////////

///kansh's algorithm
bool topological_check_for_loop(vector<int> arr[],int indegree[],int v)
{
   queue<int> q;
   int count =0;
   for(int i=0;i<v;i++)
   {
   	if(indegree[i]==0)
   	{
   		q.push(i);
   	}
   }
   while(q.empty()==false)
   {
   	int u=q.front();
   	q.pop();
   	for(int x: arr[u])
   	{
   		indegree[x]--;
   		if(indegree[x]==0)
   		{
   			q.push(x);
   		}

   	}
   	count++;
   }
   if(count!=v)
   {
   	return true;
   }
   return false;
}

///////////////topological sorting using DFS////////////////
void topological_DFS2(vector<int> arr[],bool visited[],stack<int> *st,int source)
{
	visited[source]=true;
	for(int x:arr[source])
	{
		if(visited[x]==false)
		{
			topological_DFS2(arr,visited,st,x);
		}
	}
	st->push(source);
}

void topological_DFS(vector<int> arr[],int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	stack<int> st;
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			topological_DFS2(arr,visited,&st,i);
		}
	}
	while(st.empty()==false)
	{
		cout<<st.top()<<" ";
		st.pop();
	}
}


////////////////////////check loop does not work for the directed graph //////////////////////////
bool check_loop_directed2(vector<int> arr[],bool visited[],bool rec_stack[],int source)
{
    visited[source]=true;
    rec_stack[source]=true;
    for(int x:arr[source])
    {
    	if(visited[x]==false)
    	{
    		if(check_loop_directed2(arr,visited,rec_stack,x))
    		{
    			return true;
    		}
    	}
    	else if(rec_stack[x]==true)
    	{
    		return true;
    	}
    }
    rec_stack[source]=false;
    return false;
}

bool check_loop_directed(vector<int> arr[],int v)
{
	bool visited[v];
	bool rec_stack[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
		rec_stack[i]=false;
	}
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			if(check_loop_directed2(arr,visited,rec_stack,i))
			{
				cout<<"yes loop exist"<<endl;
				return true;
			}
		}
	}
	return false;
}
void show(vector<int> arr[],int v)
{
	for(int i=0;i<v;i++)
	{
		for(int x: arr[i])
		{
			cout<<x<<" ";
		}
		cout<<"\n";
	}

}
int main()
{

	int v=4;
	vector<int> brr[v];
	int indegree[v];
	for(int i=0;i<v;i++)
	{
		indegree[i]=0;
	}
    add(brr,indegree,0,1);
    add(brr,indegree,1,2);
    add(brr,indegree,1,3);
    add(brr,indegree,3,2);
  // cout<<"show fxn called  "; show(brr,v);    
  // cout<<"BFS called "; BFS_disconnected(brr,v);
  //  cout<<endl;
  //  check_loop_directed(brr,v);
   // cout<<"topological check for loop :";
   // if(topological_check_for_loop(brr,indegree,v))
   // {
   // 	cout<<"yes loop is there";
   // }
   // else{
   // 	cout<<"No loop there"<<endl;
   // }
  // cout<<"DFS called "; DFS(brr,v);
  // cout<<"\ntopological called "; topological(brr,indegree,v);
  cout<<"\ntopological called "; topological_DFS(brr,v);

}