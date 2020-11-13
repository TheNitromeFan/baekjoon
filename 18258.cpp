#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	queue<int> q;
	for(int inst = 0; inst < n; ++inst){
		char order[10];
		scanf("%s", order);
		if(order[1] == 'u'){
			int x;
			scanf("%d", &x);
			q.push(x);
		}else if(order[1] == 'o'){
			if(q.empty()){
				printf("-1\n");
			}else{
				int y = q.front();
				q.pop();
				printf("%d\n", y);
			}
		}else if(order[1] == 'i'){
			printf("%d\n", q.size());
		}else if(order[1] == 'm'){
			printf("%d\n", q.empty());
		}else if(order[1] == 'r'){
			if(q.empty()){
				printf("-1\n");
			}else{
				printf("%d\n", q.front());
			}
		}else if(order[1] == 'a'){
			if(q.empty()){
				printf("-1\n");
			}else{
				printf("%d\n", q.back());
			}
		}
	}
	return 0;
}
