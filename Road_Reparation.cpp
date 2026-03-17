#include<bits/stdc++.h>
using namespace std;




int find(int x,vector<int> &parent){
    if(parent[x]==x) return x;
    return parent[x] = find(parent[x],parent);
}

void merge(int x,int y,vector<int> &parent,vector<int> &rank){
    x= find(x,parent);
    y=find(y,parent);

    if(x==y) return;
    if(rank[x]>rank[y]) parent[y] =x;
    
    else if(rank[y]>rank[x]) parent[x] =y;
    else {parent[x] =y;
         rank[y]++;
    }
}

int main(){
int n,m;
cin>>n>>m;
vector<int > parent(n+1);
vector<int > rank(n+1,0);
for(int i=1;i<=n;i++) parent[i]=i;


priority_queue<pair<int,pair<int,int>>> pq;
for(int i=0;i<m;i++){
    int a,b,c;cin>>a>>b>>c;
    pq.push(make_pair(-c,make_pair(a,b)));

}

int count=0;
long long cost=0;
while (!pq.empty() && count<n-1)
{
    auto top =pq.top();
    pq.pop();

    int x=top.second.first;
    int y=top.second.second;

    if(find(x,parent)!=find(y,parent)){

        merge(x,y,parent,rank);
        cost-=top.first;
        count++;

    }
}

int parentf = find(1,parent);
for(int i=2;i<=n;i++){
    if(parentf != find(i,parent)){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
}

cout<<cost<<"\n";


	return 0;
}