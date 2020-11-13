#include <cstdio>
#include <queue>

int main(){
	int n;
	scanf("%d", &n);
	std::queue<int> q;
	for(int i = 1; i <= n; ++i){
		q.push(i);
	}
	int sign = 1;
	while(!q.empty()){
		if(sign == 1){
			printf("%d ", q.front());
			q.pop();
		}else{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		sign *= -1;
	}
	return 0;
}
