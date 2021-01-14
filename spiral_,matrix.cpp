
#include <bits/stdc++.h> 
using namespace std; 

class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > v, int r, int c) 
    {
 vector<int> s;
 int rown=0;
  r=r-1;
  c=c-1;
while(rown<=r && rown<=c){
  for(int i=rown;i<=c;i++)
  {
     s.push_back(v[rown][i]);
  }
  for(int i=rown+1;i<=r && rown!=r;i++)
  {
    s.push_back(v[i][c]);
  }
  for(int i=c-1;i>=rown&& rown!=r ;i--)
  {
     s.push_back(v[r][i]);
  }
  for(int i=r-1;i>=rown+1 && rown!=c;i--)
  {
     s.push_back(v[i][rown]);
  }
  rown++;
  r--;
  c--;
}
return s; 
  }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  