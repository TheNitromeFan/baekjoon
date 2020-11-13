#include <cstdio>
void pare_branch(bool a[][50], int sz, int d){
	for(int v = 0; v < sz; ++v){
		if(a[d][v]){
			a[d][v] = false;
			pare_branch(a, sz, v);
		}
	}
}


int count_leaves(bool a[][50], int sz, int start){
	bool is_child = true;
	int running_sum = 0;
	for(int v = 0; v < sz; ++v){
		if(a[start][v]){
			is_child = false;
			running_sum += count_leaves(a, sz, v);
		}
	}
	return is_child ? 1 : running_sum;
}

int main(){
	int n;
	scanf("%d", &n);
	bool adj[50][50]; // adj[u][v] gives the existence of a branch from u to v
	for(int i = 0; i < 50; ++i){
		for(int j = 0; j < 50; ++j){
			adj[i][j] = false;
		}
	}
	int head;
	for(int v = 0; v < n; ++v){
		int u;
		scanf("%d", &u);
		if(u != -1){
			adj[u][v] = true;
		}else{
			head = v;
		}
	}
	int del;
	scanf("%d", &del);
	if(head == del){
		printf("0");
		return 0;
	}
	for(int u = 0; u < n; ++u){
		adj[u][del] = false;
	}
	pare_branch(adj, n, del);
	printf("%d", count_leaves(adj, n, head));
	return 0;
}
