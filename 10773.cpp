#include <cstdio>
#include <stack>

int main(){
	int k;
	scanf("%d", &k);
	std::stack<int> s;
	for(int i = 0; i < k; ++i){
		int x;
		scanf("%d", &x);
		if(x == 0){
			s.pop();
		}else{
			s.push(x);
		}
	}
	int sum = 0;
	while(!s.empty()){
		sum += s.top();
		s.pop();
	}
	printf("%d", sum);
	return 0;
}
