/*

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
vector<string> dirs={"h","v","d"};
int mazePath(int sr,int sc, int er,int ec, vector<vector<int>> dir,string psf) {
   if(sr==er && sc==ec) {
       cout<<psf<<endl;
       return 1;
   }
   int count=0;
   for(int i=0;i<dir.size();i++){
       int r = sr +dir[i][0];
       int c = sc +dir[i][1];
       if(r>=0 && c>=0 && r<=er && c<=ec){
         count+=mazePath(r,c,er,ec,dir,psf+dirs[i]);
       }
   }
   return count;
}

int mazePathJump(int sr,int sc, int er,int ec, vector<vector<int>> dir,string psf) {
   if(sr==er && sc==ec) {
       cout<<psf<<endl;
       return 1;
   }
   int count=0;
   for(int i=0;i<dir.size();i++){
       for(int rad =1;rad < max(ec,er);rad++){
       int r = sr + rad*dir[i][0];
       int c = sc + rad*dir[i][1];
       if(r>=0 && c>=0 && r<=er && c<=ec){
         count+=mazePathJump(r,c,er,ec,dir,psf+dirs[i]+to_string(rad));
       }
       }
   }
   return count;
}

int floodFill(int sr,int sc, int er,int ec, vector<vector<bool>> &visited, vector<vector<int>> dir,string psf) {
   if(sr==er && sc==ec) {
       cout<<psf<<endl;
       return 1;
   }
   int count=0;
   visited[sr][sc] = true;
   for(int i=0;i<dir.size();i++){
       int r = sr +  dir[i][0];
       int c = sc +  dir[i][1];
       if(r>=0 && c>=0 && r<=er && c<=ec && !visited[r][c]){
         count+=floodFill(r,c,er,ec,visited,dir,psf+dirs[i]);
       }
   } 
   visited[sr][sc] =false;
   return count;
}

int floodFillJump(int sr,int sc, int er,int ec, vector<vector<bool>> &visited, vector<vector<int>> dir,string psf) {
   if(sr==er && sc==ec) {
       cout<<psf<<endl;
       return 1;
   }
   int count=0;
   visited[sr][sc] = true;
   for(int i=0;i<dir.size();i++){
       for(int rad = 1;rad<= max(er,ec);rad++){
       int r = sr +  rad*dir[i][0];
       int c = sc +  rad*dir[i][1];
       if(r>=0 && c>=0 && r<=er && c<=ec && !visited[r][c]){
         count+=floodFillJump(r,c,er,ec,visited,dir,psf+dirs[i]+to_string(rad));
       }
       }
   } 
   visited[sr][sc] =false;
   return count;
}

int coinSwitchWithPermutationAll(vector<int> coins,int tar,string psf){
   if(tar == 0 ){
       cout<<psf<<endl;
     return 1;
   }
    int count =0;
    for(int i=0;i<coins.size();i++) {
        if(tar-coins[i]>=0)
        count+= coinSwitchWithPermutationAll(coins,tar-coins[i],psf+to_string(coins[i]));
    }
    return count;
}  

int coinSwitchWithCombinationAll(vector<int> coins,int tar,int idx,string psf){
   if(tar == 0 ){
       cout<<psf<<endl;
     return 1;
   }
    int count =0;
    for(int i=idx;i<coins.size();i++) {
        if (tar-coins[i]>=0)
        count+= coinSwitchWithCombinationAll(coins,tar-coins[i],i,psf+to_string(coins[i]));
    }
    return count;
}  

int coinSwitchWithPermutationSing(vector<int> coins,int tar,string psf){
   if(tar == 0 ){
       cout<<psf<<endl;
     return 1;
   }
    int count =0;
    for(int i=0;i<coins.size();i++) {
        int val  = coins[i];
        
        if(tar-coins[i]>=0 && coins[i]>0){
            coins[i] = -coins[i];
        count+= coinSwitchWithPermutationSing(coins,tar-val,psf+to_string(val));
        coins[i] = -coins[i];
        }
    }
    return count;
}  
int coinSwitchWithCombinationSing(vector<int> coins,int tar,int idx,string psf){
   if(tar == 0 ){
       cout<<psf<<endl;
     return 1;
   }
    int count =0;
    for(int i=idx;i<coins.size();i++) {
        int val  = coins[i];
        
        if(tar-coins[i]>=0 && coins[i]>0){
        coins[i] = -coins[i];
        count+= coinSwitchWithCombinationSing(coins,tar-val,i,psf+to_string(val));
        coins[i] = -coins[i];
        }
    }
    return count;
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> dir = {{0,1},{1,0},{1,1}};
    vector<vector<bool>> visited;
    for(int i=0;i<4;i++){
        vector<bool> v;
        for(int j=0;j<4;j++){
            v.push_back(false);
        }
        visited.push_back(v);
    }
    // cout<<mazePath(1,1,3,3,dir,"")<<endl;
    // cout<<floodFill(1,1,3,3,visited,dir,"")<<endl;
    // cout<<floodFillJump(1,1,3,3,visited,dir,"")<<endl;
    vector<int> coins = {2,3,5,10} ;
    // cout<<coinSwitchWithPermutationAll(coins,10,"")<<endl;
    // cout<<coinSwitchWithCombinationAll(coins,10,0,"")<<endl;
//    cout<<coinSwitchWithPermutationSing(coins,10,"")<<endl; 
    cout<<coinSwitchWithCombinationSing(coins,10,0,"")<<endl;

    return 0;
}

