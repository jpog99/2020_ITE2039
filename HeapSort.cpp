//2019007901_Wan_11802
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void Heapify(int arr[], int parent, int last){
    int child=2*parent;
    int big_child;

    while(child<=last){
        if(child+1>last){
            big_child = child;
            if(arr[parent]<arr[big_child]) swap(&arr[parent],&arr[big_child]);
        }else{
            big_child = arr[child]>arr[child+1]? child:child+1;
            if(arr[parent]<arr[big_child]) swap(&arr[parent],&arr[big_child]);
        }
        parent=big_child;
        child=parent*2;
    }
}

int removeHighest(int arr[],int heapsize){
    swap(&arr[1],&arr[heapsize]);
    heapsize--;
    Heapify(arr,1,heapsize);
    return arr[heapsize+1];
}

void BuildMaxHeap(int arr[],int size){
    for(int i=size/2 ; i>0; i--)
        Heapify(arr,i,size);
}

int main() {
    int size,k;
    scanf("%d%d",&size,&k);
    int arr[size+1];
    for(int i=1 ; i<size+1 ; i++)
        scanf("%d",&arr[i]);

    BuildMaxHeap(arr,size);
    int heapsize=size;

    for(int i=0 ; i<k ; i++){
        printf("%d ",removeHighest(arr,heapsize));
        heapsize--;
    }

    printf("\n");
    for(int i=1 ; i<size-k+1 ; i++)
        printf("%d ",arr[i]);
  return 0;
}