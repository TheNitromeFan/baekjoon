#include <cstdio>

int main(){
	int prev, cur;
	scanf("%d %d", &prev, &cur);
	int ind = 2;
	while(true){
		int next = prev - cur;
		++ind;
		if(next > cur){
			break;
		}
		prev = cur;
		cur = next;
	}
	printf("%d", ind);
	return 0;
}
