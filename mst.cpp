//201907901_Wan_11802
#include <stdio.h>
#include <stdlib.h>


int N,M;

typedef struct Edge {
    int from, to, weight;
}Edge;

typedef struct vertice {
    int parent;
    int rank;
}vertice;

Edge* edge;
vertice vertices[1000];

void swap(Edge* a, Edge* b)
{
    Edge t = *a;
    *a = *b;
    *b = t;
}

int find_set(int i)
{
    //path compression
    if (vertices[i].parent != i)
        vertices[i].parent = find_set(vertices[i].parent);
    return vertices[i].parent;
}

void Union(int x, int y)
{
    int xroot = find_set(x);
    int yroot = find_set(y);

    if (vertices[xroot].rank < vertices[yroot].rank)
        vertices[xroot].parent = yroot;
    else if (vertices[xroot].rank > vertices[yroot].rank)
        vertices[yroot].parent = xroot;

    else
    {
        vertices[yroot].parent = xroot;
        vertices[xroot].rank++;
    }
}

void KruskalMST()
{
    Edge result[N];
    int e=0;
    int i=0;


    for (int v = 0; v < N; ++v) {
        vertices[v].parent = v;
        vertices[v].rank = 0;
    }

    while (e<N-1 && i<M) {

        Edge next_edge = edge[i++];

        int x = find_set(next_edge.from);
        int y = find_set(next_edge.to);

        if (x != y) {
            result[e++] = next_edge;
            Union(x, y);
        }
    }
    printf("%d\n",e);

    for (i = 0; i < e; ++i)
    {
        printf("%d %d %d\n", result[i].from+1, result[i].to+1, result[i].weight);
    }
    return;
}

void create_graph(int E){
    edge = new Edge[E];
}

int partition (int low, int high)
{
    Edge pivot = edge[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        //sort by weight, then by x, then by y
        if (edge[j].weight < pivot.weight || (edge[j].weight == pivot.weight && edge[j].from < pivot.from) || (edge[j].weight == pivot.weight && edge[j].from == pivot.from && edge[j].to < pivot.to))
        {
            i++;
            swap(&edge[i], &edge[j]);
        }
    }
    swap(&edge[i + 1], &edge[high]);
    return (i + 1);
}


void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int main()
{
    Edge temp;
    scanf("%d %d",&N,&M);
    create_graph(M);

    for(int i=0 ; i<M ; i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        x--,y--;
        edge[i].from = x;
        edge[i].to = y;
        edge[i].weight = w;
    }

    //sort edges by weight
    quickSort(0,M-1);

    KruskalMST();

    return 0;
}