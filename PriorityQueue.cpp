//2019007901_Wan_11802
#include <stdio.h>

int heap_size = 0;
const int MAX_SIZE = 100000;

void swap( int *a, int *b ) {
  int t;
  t = *a;
  *a = *b;
  *b = t;
}


void max_heapify(int A[], int index) {

  //percolate up
  if(index != 1 && A[index]>A[index/2]){
    while(index!=1){
        if(A[index]>A[index/2]){
            swap(&A[index], &A[index/2]);
            index = index / 2;
        }else break;
    }
  }

  //percolate down
  else{
      while(1){
        if (index * 2 > heap_size) return; //when current index is at bottom level
        if (A[index]>=A[index*2] && A[index]>=A[index*2+1]) return; //when current index is bigger than both child

        //left child > right case
        if (A[index*2] > A[index*2+1]) {
            swap(&A[index], &A[index*2]);
            index = index*2;
        }else{
        //right child > left case
            swap(&A[index],&A[index*2+1]);
            index = index*2+1;
        }
      }
  }
}

int extract_max(int A[]) {
  int maxm = A[1];
  A[1] = A[heap_size];
  A[heap_size--]=0;
  max_heapify(A, 1);
  return maxm;
}

void insert(int A[], int key) {
  heap_size++;
  int i = heap_size;
  A[heap_size] = key;
  max_heapify(A,i);
}

void print_heap(int A[]) {
  int i;
  for(i=1; i<=heap_size; i++) {
    printf("%d ",A[i]);
  }
}

int main() {
    int arr[MAX_SIZE];
    int extracted[MAX_SIZE];
    int new_num,cnt=0,menu=1;

    while(menu!=0){
        scanf("%d",&menu);
        switch(menu){
        case 1:
            scanf("%d",&new_num);
            insert(arr,new_num);break;
        case 2:
            extracted[cnt]=extract_max(arr);
            cnt++; break;
        case 3:
            int index;
            scanf("%d%d",&index,&new_num);
            arr[index] = new_num;
            max_heapify(arr,index);
            break;
        default:
            break;
        }
    }

    for(int i=0 ; i<cnt ; i++){
        printf("%d ",extracted[i]);
    }

    printf("\n");
    print_heap(arr);
  return 0;
}