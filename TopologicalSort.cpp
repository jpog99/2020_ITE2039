//2019007901_Wan_11802
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int N,M;
list<int> *vertices;
stack<int> Stack; //stack to store result
bool visited[1000];


void create_graph(int n){
    vertices = new list<int>[N];
}

void create_edge(int from, int to){
    vertices[from].push_back(to);
}

bool is_DAG_helper(int v, bool visited[], bool *recStack){
        if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
        list<int>::iterator i;
        for(i = vertices[v].begin(); i != vertices[v].end(); ++i)
        {
            if ( !visited[*i] && is_DAG_helper(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool is_DAG(){
    bool *visited = new bool[N];
    bool *recStack = new bool[N];
    for(int i = 0; i < N; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i = 0; i < N; i++)
        if (is_DAG_helper(i, visited, recStack))
            return false;
    return true;
}

void topo_sort_helper(int v, bool visited[]){
    visited[v] = true;
    vertices[v].sort();

    list<int>::iterator i;
    for (i = vertices[v].begin(); i != vertices[v].end(); ++i)
        if (!visited[*i])
            topo_sort_helper(*i, visited);
    Stack.push(v);
}

void topo_sort(){
    for (int i = 0; i < N; i++)
        visited[i] = false;

    for (int i = 0; i < N; i++)
        if (visited[i] == false)
            topo_sort_helper(i, visited);

    while (Stack.empty() == false) {
        printf("%d ",Stack.top()+1);
        Stack.pop();
    }
}

int main()
{
    scanf("%d %d",&N,&M);
    create_graph(N);
    for(int i=0 ; i<M ; i++){
        int from ,to;
        scanf("%d %d",&from, &to);
        from--;to--;
        create_edge(from,to);
    }


    if(is_DAG()){
        printf("1\n");
        topo_sort();
    }
    else{
        printf("0\n");
    }
    return 0;
}