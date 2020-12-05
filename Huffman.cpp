//2019007901_Wan_11802
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;

//0 or 1 that represents the tree branches
typedef struct treePathBits{
    int x,y;
}treePathBits;

priority_queue<pair<int, pair<int,int> > > pq;
pair<treePathBits,int> arr[100000];
int total_bits;

void extract_min(int x, int str_len) {
	pair<treePathBits, int> current_node = arr[x];
	if (current_node.first.x == -1 && current_node.first.y == -1) {
		total_bits += (str_len*current_node.second);
		return;
	}
	extract_min(current_node.first.x, str_len+1);
	extract_min(current_node.first.y, str_len+1);
}

void HuffmanCode(int c){
    while (pq.size()>1) {
		pair<int, pair<int,int> > tree1 = pq.top(), tree2;
		pq.pop();
		tree2 = pq.top();
		pq.pop();

		if (tree1.second.first != 0)
            arr[tree1.second.second] = { {-1,-1}, tree1.second.first };
		if (tree2.second.first != 0)
            arr[tree2.second.second] = { { -1,-1 }, tree2.second.first };

		arr[c] = { {tree1.second.second,tree2.second.second},0 };
		pq.push({ tree1.first + tree2.first, {0, c++} });
	}

	extract_min(c-1,0);

}

void fixedLength(int s, int n){
    int bit_len = 1;
    int string_len = n;
    while (string_len > 1){
        string_len /= 2;
        bit_len++;
    }
    printf("%d\n",s*bit_len);
}

int main(void){
    int n,s,c,freq[30000];
    string str;
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++){
        cin >> str >> freq[i];
        pq.push({ -freq[i],{freq[i],c++} });
    }
    scanf("%d",&s);

    fixedLength(s,n);
    HuffmanCode(c);
    printf("%d", total_bits);

    return 0;
}