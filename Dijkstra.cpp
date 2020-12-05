//2019007901_Wan_11802
#include<bits/stdc++.h>
#include <stdio.h>
#define INF 1000000
using namespace std;
int N,M;
list< pair<int, int> > *adj;

void addEdge(int x, int y, int w)
{
    adj[x].push_back(make_pair(y, w));
}

int relax(int* v, int u, int w){
    //if neighbour's distance (v) > current + weight to neighbor (u), change neighbor's distance
    if (*v > u + w){
        *v = u + w;
        return 1;
    }
    else return 0;
}

void Dijkstra(){
    priority_queue< pair<int,int>, vector <pair<int,int> > , greater<pair<int,int> > > pq;
    vector<int> dist(N, INF);

    //add the source into minheap with distance=0;
    int source = 0;
    pq.push(make_pair(source, 0));
    dist[source] = 0;

    while (!pq.empty())
    {
        int curr = pq.top().first; //current = the name of vertex at top of heap
        pq.pop();

        //iterate through all neighbors of node that just popped from heap
        for (list< pair<int, int> >::iterator i=adj[curr].begin(); i != adj[curr].end(); i++)
        {
            int neighbor = (*i).first;
            int neighbor_w = (*i).second; //neighbor's current shortest distance from source
            
            if( relax(&dist[neighbor], dist[curr], neighbor_w) )
                pq.push(make_pair(neighbor, dist[neighbor])); //update neighbor distance in heap
        }
    }

    int ans = 0;
    for (int i=0; i<N; i++)
        ans = dist[i]>ans? dist[i]:ans;
    printf("%d",ans);
}

int main()
{
    scanf("%d %d",&N,&M);
    adj = new list< pair<int,int> > [N];

    for(int i=0 ; i<M ; i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        x--,y--;
        addEdge(x,y,w);
    }
    Dijkstra();
    return 0;
}
