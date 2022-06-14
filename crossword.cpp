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


bool ispossiblePlace_h(vector<vector<char>> board,string word,int r,int c){
    int l=word.length(), n=board[0].size();
    if(c+l>n) return false;
    if(c==0 && c+l<n && board[r][c+l]!='+') return false;
    if(c!=0 && c+l==n && board[r][c-1]!='+') return false;
    if(c!=0 && c+l<n && (board[r][c+l]!='+' && board[r][c-1]!='+'))
     for(int i=0;i<word.length();i++){
         if(board[r][c+i]!='-' && word[i]!=board[r][c+i]) return false;
     }
     return true;
}
int place_h(vector<vector<char>> board,string word,int r,int c){
    int loc =0;
    for(int i=0;i<word.length();i++){
        if(board[r][c+i]=='-'){
            loc^=(1<<i);
            board[r][c+i]=word[i];
        }
    }  
    return loc;
}
void unplace_h(vector<vector<char>> board,string word,int r,int c,int loc){

    for(int i=0;i<word.length();i++){
        int mask = (1<<i);
        if((loc & mask)!=0){
            board[r][c+i]='-';
        }
    }  
}
bool ispossiblePlace_v(vector<vector<char>> board,string word,int r,int c){
    int l=word.length(), n=board.size();
    if(r+l>n) return false;
    if(r==0 && r+l<n && board[r+l][c]!='+') return false;
    if(r!=0 && r+l==n && board[r-1][c]!='+') return false;
    if(r!=0 && r+l<n && (board[r+l][c]!='+' && board[r-1][c]!='+'))
     for(int i=0;i<word.length();i++){
         if(board[r+i][c]!='-' && word[i]!=board[r+i][c]) return false;
     }
     return true;
}
int place_v(vector<vector<char>> board,string word,int r,int c){
     int loc =0;
    for(int i=0;i<word.length();i++){
        if(board[r+i][c]=='-'){
            loc^=(1<<i);
            board[r+i][c]=word[i];
        }
    }  
    return loc;
}
void unplace_v(vector<vector<char>> board,string word,int r,int c,int loc){
    for(int i=0;i<word.length();i++){
        int mask = (1<<i);
        if((loc & mask)!=0){
            board[r+i][c]='-';
        }
    }  
}
int crossWord(vector<vector<char>> board,vector<string> words,int idx){
    if(idx==words.size()) {
        return 1;
    }
    string word = words[idx];
    int n= board.size(),m=board[0].size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='-' || board[i][j]==word[0]){
                if(ispossiblePlace_h){
                    int loc=place_h(board,word,i,j);
                    count+=crossWord(board,words,idx+1);
                    unplace_h(board,word,i,j,loc);
                }
                if(ispossiblePlace_v){
                    int loc=place_v(board,word,i,j);
                    count+=crossWord(board,words,idx+1);
                    unplace_v(board,word,i,j,loc); 
                }
            }
        }
    }
    return count;
}

//kth subset sum
int kSubSetSum(vector<int> v,int idx,vector<int> sum,vector<vector<int>> sets){
    if(idx==v.size()){
        for(int i=0;i<sum.size();i++){
            if(sum[i]!=sum[i-1]) return 0;
        }
        for(auto x: sets){
            cout<<"[";
            for(auto q:x) cout<<q<<" ";
            cout<<"]";
        }
        return 1;
    }
    int k = sum.size(), count=0;
    for(int i=0;i<k;i++){
        sum[i]+=v[idx];
        sets[i].push_back(v[idx]);
        count+=kSubSetSum(v,idx+1,sum,sets);
        sets[i].pop_back();
        sum[i]-=v[idx];
    }
    return count;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k=3;
    vector<int> v={1,2,3,4,5,6};
    vector<vector<int>> vv;
    vector<int> sum(k);
    cout<<kSubSetSum(v,0,sum,vv)<<endl;
    



    return 0;
}

