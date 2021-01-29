#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void add(vector<int> arr[],int v,int u)
{
	
    arr[v].push_back(u);
    arr[u].push_back(v);
    
}
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
bool check_loop2(vector<int> arr[],bool visited[],int source,int parent)
{
    visited[source]=true;
    for(int x: arr[source])
    {
    	if(visited[x]==false)
    	{
    		if(check_loop2(arr,visited,x,source)==true)
    		{
    			return true;
    		}
    	}
    	else if(x!=parent)
    	{
    		return true;
    	}
    }
    return false;
}
bool check_loop(vector<int> arr[],int v){
	bool visited[v];
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<v;i++)
	{
		if(visited[i]==false)
		{
			if(check_loop2(arr,visited,i,-1)==true)
			{
				cout<<"true there loop exist"<<endl;
				return true;
			}
		}
	}
	cout<<"no there no loop exist"<<endl;
	return false;
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

	int v=3;
	vector<int> brr[v];
    add(brr,1,0);
    add(brr,2,1);
      add(brr,2,0);
      // add(brr,4,2);
    show(brr,v);    
   BFS_disconnected(brr,v);
   cout<<endl;
   check_loop(brr,v);
  DFS(brr,v);
}