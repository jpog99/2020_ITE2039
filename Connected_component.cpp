//2019007901_Wan_11802
#include <stdio.h>
#include <stdlib.h>
#include <list>
using namespace std;

int ans;
int N,M;
list<int>* vertices;

void create_graph(int n){
    vertices = new list<int>[N];
}

void create_edge(int from, int to){
    vertices[from].push_back(to);
    vertices[to].push_back(from);
}

void dfs(int v, bool visited[]){

    visited[v] = true;
    list<int>::iterator i;
    for (i = vertices[v].begin(); i != vertices[v].end(); ++i)
        if (!visited[*i])
            dfs(*i, visited);
}

void connected_comp(){
    bool* visited = new bool[N];
    for (int i=0; i< N; i++)
        visited[i] = false;

    for (int i=0; i<N; i++) {
        if (visited[i] == false) {
            dfs(i,visited);
            ans++;
        }
    }
    delete[] visited;
}

int main()
{

    scanf("%d %d",&N,&M);
    create_graph(N);
    for(int i=0 ; i<M ; i++){
        int from ,to;
        scanf("%d %d",&from, &to);
        from--;to--;
        create_edge(from, to);
    }

    connected_comp();
    printf("%d",ans);

    return 0;
}