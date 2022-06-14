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

///sudoku solving

bool isSafePosition(vector<vector<char>> board,int r,int c,int num){
    //row
    for(int i=0;i<9;i++){
        if(board[r][i]-'0' == num) return true;
    }
    //col
    for(int i=0;i<9;i++){
        if(board[i][c]-'0'== num) return true;
    }
    // matrix
    r = (r/3)*3;
    c = (c/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
        char number = num+'0';
        if(board[r+i][c+j]-'0'==num) return true;
        }
    }
    return false;
}
bool solveSudoku(vector<vector<char>> board,vector<int> emptyVector,int idx){
    if(idx==emptyVector.size()) return true;
    int cell= emptyVector[idx];
    int r = cell/9;
    int c=cell%9;
    for(int num=1;num<=9;num++){
        if(isSafePosition(board,r,c,num)) {
        board[r][c] = num + '0';
        if(solveSudoku(board,emptyVector,idx+1)) return true;
        board[r][c]='.';
        }
    }
    return false;
}


void emptyCreationSolveSudoku(vector<vector<char>> board){
    vector<int> emptyVector;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.')
             emptyVector.push_back(i*9+j);
        }
    }
    solveSudoku(board,emptyVector,0);
}


// //leetcode
// bool isSafePosition(vector<vector<char>> board,int r,int c,int num){
//   //row
//     for(int i=0;i<9;i++){
//         if(board[r][i]-'0' == num) return false;
//     }
//     //col
//     for(int i=0;i<9;i++){
//         if(board[i][c]-'0' == num) return false;
//     }
//     // matrix
//     r = (r/3)*3;
//     c = (c/3)*3;
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//         if(board[r+i][c+j]-'0'==num) return false;
//         }
//     }
//     return true;
// }
// bool solveSudoku(vector<vector<char>>& board,vector<int> emptyVector,int idx){
//     if(idx==emptyVector.size()) return true;
//     int cell= emptyVector[idx];
//     int r = cell/9;
//     int c=cell%9;
//     for(int num=1;num<=9;num++){
//         if(isSafePosition(board,r,c,num)) {
//         board[r][c] = num + '0';
//         if(solveSudoku(board,emptyVector,idx+1)) return true;
//         board[r][c]='.';
//         }
//     }
//     return false;
// }

// void solveSudoku(vector<vector<char>>& board) {
//        vector<int> emptyVector;
//         for(int i=0;i<9;i++){
//             for(int j=0;j<9;j++){
//                 if(board[i][j]=='.')
//                  emptyVector.push_back(i*9+j);
//             }
//         }
//         solveSudoku(board,emptyVector,0);  
//     }
// }
///////
//word break problem
int wordBreak(string s,set<string> dict,int maxLength,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count =0;
   for(int i=0;i<s.length();i++){
       string ns = s.substr(0,i+1);
       if(ns.length()>maxLength) break;
       if(dict.find(ns)!=dict.end()){
          count+= wordBreak(s.substr(i),dict,maxLength,ans+ns+" ");
       }
   }
   return count;
}
///////////

//ABCD 

int friendPair(string s,vector<bool> used,string ans){
    int idx=0;
    while(used[idx] && idx<s.length()) idx++;
    if(idx==s.length()) {
        cout<<ans<<endl;
        return 1;
    };
    int count =0;
    used[idx] =true;
    count+= friendPair(s,used,ans+"("+s[idx]+")");
    for(int i=idx+1;i<s.length();i++){
        if(!used[i]){
            used[i]=true;
            count+=friendPair(s,used,ans+"("+s[idx]+ "," +s[i]+")");
            used[i]=false;
        }
    }
    used[idx] =false;
    return count;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> v(3,false);
    cout<<friendPair("ABC",v,"");


    return 0;
}

