#/*

Author : Ankit Sharma

github:https://github.com/ankitkumar2698

linkedin : https://www.linkedin.com/in/ankitsharmakaushik

*/


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <bitset>
#include <set>
#include <map>
#include <iterator>


using namespace std;
#define ll long long
#define ull unsigned long long


//Sort array in discending order (n to 1)
bool decSort(ll a,ll b){
    return a>b;
}


//find the maximum element of a array
ll max_of_array(ll a[],ll n){
    ll mx=a[0];
    for(ll i=0;i<n;i++){
        if(a[i]>mx) mx = a[i];
    }
    return mx;
}


//find the minimum element of a array
ll min_of_array(ll a[],ll n){
    ll mn=a[0];
    for(ll i=0;i<n;i++){
        if(a[i]<mn) mn = a[i];
    }
    return mn;
}


bool isPrime(ll n){
    if(n==1) return false;
    if(n==2) return true;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

int queenPathCombination(vector<bool> box,int tnq,int idx,int qpsf,string psf){
    if(tnq == qpsf){
        cout<<psf<<endl;
        return 1;
    }
    int count =0;
    for(int i =idx;i<box.size();i++){
       count+= queenPathCombination(box,tnq,i+1,qpsf+1,(psf+" "+to_string(i)+" "));
    }
    return count;
}

int queenPathPermutation(vector<bool> box,int tnq,int qpsf,string psf){
    if(tnq == qpsf){
        cout<<psf<<endl;
        return 1;
    }
    int count =0;
    for(int i =0;i<box.size();i++){
        if(!box[i]){
            box[i]=true;
            count+= queenPathPermutation(box,tnq,qpsf+1,(psf+" "+to_string(i)+" "));
            box[i]=false; 
        }
    }
    return count;
}
int queenTwoDCombination(vector<vector<bool>> box,int tnq,int qpsf,int col,int row,string psf){
       if(qpsf==tnq){
           cout<<psf<<endl;
           return 1;
       }
       int count = 0;
       for(int i=row;i<box.size();i++){
           for(int j=col;j<box[0].size();j++){
               count+= queenTwoDCombination(box,tnq,qpsf+1,j+1,i,psf+" "+to_string(i)+","+to_string(j)+" ");
           }
           col=0;
       }
       return count;
}
int queenTwoDPermutation(vector<vector<bool>> box,int tnq,int qpsf,string psf){
       if(qpsf==tnq){
           cout<<psf<<endl;
           return 1;
       }
       int count = 0;
       for(int i=0;i<box.size();i++){
           for(int j=0;j<box[0].size();j++){
               if(!box[i][j]){
                   box[i][j] =true;
               count+= queenTwoDPermutation(box,tnq,qpsf+1,psf+" "+to_string(i)+","+to_string(j)+" ");
               box[i][j] =false;
               }
           }
       }
       return count;
}
//second method
int queenTwoDCombination2nd(vector<vector<bool>> box,int tnq,int idx,string psf){
       if(tnq==0){
           cout<<psf<<endl;
           return 1;
       }
       int count = 0,n= box.size();
       for(int i=idx;i<n*n;i++){
          int row = i/n;
          int col = i%n;
               count+= queenTwoDCombination2nd(box,tnq-1,i+1,psf+" "+to_string(row)+","+to_string(col)+" ");
       }
       return count;
}
int queenTwoDPermutation2nd(vector<vector<bool>> box,int tnq,string psf){
       if(tnq==0){
           cout<<psf<<endl;
           return 1;
       }
       int count = 0,n = box.size();
      for(int i =0;i<n*n;i++)
           {
               int row = i/n;
               int col = i%n;
               if(!box[row][col]){
               box[row][col] =true;
               count+= queenTwoDPermutation2nd(box,tnq-1,psf+" "+to_string(row)+","+to_string(col)+" ");
               box[row][col] = false;
               }
           }
       return count;
}


///////////////////
bool issafe(vector<vector<bool>> box,int row,int col) {
    vector<vector<int>> dir = {{-1,-1},{0,-1},{-1,1},{-1,0}};
    for(int i =0;i<dir.size();i++){
        for(int j=1;j<=box.size();j++){
        int r = row + j*dir[i][0];
        int c = col+j*dir[i][1];
        if(r>=0 && c>=0 && r<box.size() && c<box.size()){
        if(box[r][c]) return false;
        }
        else break;
        }
    }
    return true;
}

///////
bool issafePermu(vector<vector<bool>> box,int row,int col) {
    vector<vector<int>> dir = {{-1,-1},{0,-1},{-1,1},{-1,0},{1,1},{0,1},{1,-1},{1,0}};
    for(int i =0;i<dir.size();i++){
        for(int j=1;j<=box.size();j++){
        int r = row + j*dir[i][0];
        int c = col+j*dir[i][1];
        if(r>=0 && c>=0 && r<box.size() && c<box.size()){
        if(box[r][c]) return false;
        }
        else break;
        }
    }
    return true;
}
int n_queen(vector<vector<bool>> box,int tnq,int idx,string psf){
       if(tnq==0){
           cout<<psf<<endl;
           return 1;
       }
       int count = 0,n= box.size();
       for(int i=idx;i<n*n;i++){
          int row = i/n;
          int col = i%n;
          if(issafe(box,row,col)){
               box[row][col]=true;
               count+= n_queen(box,tnq-1,i+1,psf+" "+to_string(row)+","+to_string(col)+" ");
               box[row][col]=false;
          }
       }
       return count;
}

//permutate

int n_queenPermu(vector<vector<bool>> box,int tnq,string psf){
       if(tnq==0){
           cout<<psf<<endl;
           return 1;
       }
       int count = 0,n= box.size();
       for(int i=0;i<n*n;i++){
          int row = i/n;
          int col = i%n;
          if(!box[row][col] && issafePermu(box,row,col)){
               box[row][col]=true;
               count+= n_queenPermu(box,tnq-1,psf+" "+to_string(row)+","+to_string(col)+" ");
               box[row][col]=false;
          }
       }
       return count;
}
//n queen optimized one
vector<bool> row;
vector<bool> col;
vector<bool> Diag;
vector<bool> Adiag;
int n_queen_Optimize(int n,int tnq,int idx,string psf){
      if(tnq==0){
           cout<<psf<<endl;
           return 1;
       }
       int count = 0;
       for(int i=idx;i<n*n;i++){
          int r = i/n;
          int c = i%n;
          if(!row[r] && !col[c] && !Diag[r+c] && !Adiag[r-c+n-1]){
              row[r] = col[c] = Diag[r+c] = Adiag[r-c+n-1] = true;
               count+= n_queen_Optimize(n,tnq-1,i+1,psf+" "+to_string(r)+","+to_string(c)+" ");
               row[r] = col[c] = Diag[r+c] = Adiag[r-c+n-1] = false; 
          }
       }
       return count;
}
///optimize permutation
int n_queen_Optimize_Permu(int n,int tnq,int idx,string psf){
      if(tnq==0){
           cout<<psf<<endl;
           return 1;
       }
       int count = 0;
       for(int i=idx;i<n*n;i++){
          int r = i/n;
          int c = i%n;
          if(!row[r] && !col[c] && !Diag[r+c] && !Adiag[r-c+n-1]){
              row[r] = col[c] = Diag[r+c] = Adiag[r-c+n-1] = true;
               count+= n_queen_Optimize_Permu(n,tnq-1,0,psf+" "+to_string(r)+","+to_string(c)+" ");
               row[r] = col[c] = Diag[r+c] = Adiag[r-c+n-1] = false; 
          }
       }
       return count;
}
  ///some more optimization 
int n_queen_Optimize2(int n,int tnq,int r,string psf){
      if(tnq==0 ){
          cout<<psf<<endl;
           return 1;
       }
       int count = 0;
       for(int c=0;c<n;c++){
          if( !col[c] && !Diag[r+c] && !Adiag[r-c+n-1]){
               col[c] = Diag[r+c] = Adiag[r-c+n-1] = true;
               count+= n_queen_Optimize2(n,tnq-1,r+1,psf+" "+to_string(r)+","+to_string(c)+" ");
               col[c] = Diag[r+c] = Adiag[r-c+n-1] = false; 
          }
       }
       return count;
}
//permu
int n_queen_Optimize2_Permu(int n,int tnq,int r,string psf){
      if(tnq==0||r>=n){ 
            if(tnq==0)
            cout<<psf<<endl;
           return tnq==0?1:0;
       }
       int count = 0;
       for(int c=0;c<n;c++){
          if(!row[r] && !col[c] && !Diag[r+c] && !Adiag[r-c+n-1]){
               row[r]= col[c] = Diag[r+c] = Adiag[r-c+n-1] = true;
               count+= n_queen_Optimize2_Permu(n,tnq-1,0,psf+" "+to_string(r)+","+to_string(c)+" ");
               row[r]= col[c] = Diag[r+c] = Adiag[r-c+n-1] = false; 
          }
       }
        count+= n_queen_Optimize2_Permu(n,tnq,r+1,psf);
       return count;
}
// bit manipulation
int colB=0;
int diagB=0;
int aDiagB=0;
int n_queen_Optimize2BIT(int n,int tnq,int r,string psf){
      if(tnq==0 ){
          cout<<psf<<endl;
           return 1;
       }
       int count = 0;
       for(int c=0;c<n;c++){
          if(((colB &(1<<c))==0) && ((diagB & (1<<(r+c)))==0) && ((aDiagB & (1<<(r-c+n-1)))==0)){
               colB^= (1<<c);
               diagB^=(1<<(r+c));
               aDiagB^=(1<<(r-c+n-1));
               count+= n_queen_Optimize2BIT(n,tnq-1,r+1,psf+" "+to_string(r)+","+to_string(c)+" ");
               colB^= (1<<c);
               diagB^=(1<<(r+c));
               aDiagB^=(1<<(r-c+n-1));
          }
       }
       return count;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> v(8,false);
    vector<vector<bool>> vv(8,v);
    // for(auto x: v) cout<<x<<endl;
    // cout<<queenPathCombination(v,3,0,0,"");
    // cout<<queenTwoDC  ombination(vv,4,0,0,0,"");
    // cout<<queenTwoDPermutation(vv,4,0,"")<<endl;
    // cout<<queenTwoDCombination2nd(vv,4,0,"")<<endl;
    // cout<<queenTwoDPermutation2nd(vv,4,"")<<endl;
    // cout<<n_queen(vv,8,0,"")<<endl;
    // cout<<n_queenPermu(vv,4,"")<<endl;
    int n=4;
    // row.resize(n,false);
    // col.resize(n,false);
    // Diag.resize(n,false);
    // Adiag.resize(n,false);
    // cout<<n_queen_Optimize(n,n,0,"");
    // cout<<n_queen_Optimize_Permu(n,n,0,"");
    // cout<<n_queen_Optimize2_Permu(n,n,0,"");
    cout<<n_queen_Optimize2BIT(n,n,0,"")<<endl;
    return 0;
}

