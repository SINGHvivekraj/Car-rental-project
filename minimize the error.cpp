#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k1,k2;
    cin>>n>>k1>>k2;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        pq.push(abs(a[i]-b[i]));
    }
    int t=k1+k2;
    while(pq.size() and t>0){
        if(pq.top()<t){
            pq.push(t-pq.top());
            t-=pq.top();
            pq.pop();
        }
        else{
            pq.push(pq.top()-t);
            t=0;
            pq.pop();
            break;
        }
    }
    long long ans=0;
    while(pq.size()){
        ans+=pq.top()*pq.top();
        pq.pop();
    }
    if(t%2==1)ans++;
    cout<<ans;

     

}