
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

int kSubSetSum(vector<int> v,int idx,vector<int> sum,vector<vector<int>> sets){
    if(idx==v.size()){
        for(int i=1;i<sum.size();i++){
            if(sum[i]!=sum[i-1]) return 0;
        }
        for(auto x: sets){
            cout<<"[";
            for(auto q:x) cout<<q<<" ";
            cout<<"]";
        }
        cout<<endl;
        return 1;
    }
    int k = sum.size(), count=0;
    for(int i=0;i<k;i++){
        if(sets[i].size()==0){
          sum[i]+=v[idx];
          sets[i].push_back(v[idx]);
          count+=kSubSetSum(v,idx+1,sum,sets);
        }else{
            sum[i]+=v[idx];
            sets[i].push_back(v[idx]);
            count+=kSubSetSum(v,idx+1,sum,sets);
            sets[i].pop_back();
            sum[i]-=v[idx];
        }
    }
    return count;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k=3;
    vector<int> v={1,2,3,4,5,6};
    vector<vector<int>> vv(k,vector<int>());
    vector<int> sum(k,0);
    cout<<kSubSetSum(v,0,sum,vv)<<endl;
    



    return 0;
}

