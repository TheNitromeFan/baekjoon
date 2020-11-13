#include <cstdio>
#include <utility>
#define MAX (1000000 + 1)

using namespace std;

void insert_value(pair<int, int> tree[MAX], int root, int val){
	if(val < root){
		if(tree[root].first == 0){
			tree[root].first = val;
		}else{
			insert_value(tree, tree[root].first, val);
		}
	}else{
		if(tree[root].second == 0){
			tree[root].second = val;
		}else{
			insert_value(tree, tree[root].second, val);
		}
	}
}

void print_tree(pair<int, int> tree[MAX], int root){
	if(tree[root].first != 0){
		print_tree(tree, tree[root].first);
	}
	if(tree[root].second != 0){
		print_tree(tree, tree[root].second);
	}
	printf("%d\n", root);
}

int main(){
	static pair<int, int> tree[MAX] = {};
	int root;
	scanf("%d", &root);
	int v;
	while(scanf("%d", &v) == 1){
		insert_value(tree, root, v);
	}
	print_tree(tree, root);
	return 0;
}
