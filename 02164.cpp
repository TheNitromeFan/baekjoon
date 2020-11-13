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
	while(q.size() > 1){
		if(sign == 1){
			q.pop();
		}else{
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		sign *= -1;
	}
	printf("%d", q.front());
	return 0;
}
