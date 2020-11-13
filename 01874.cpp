#include <cstdio>
#include <stack>

using std::stack;

int main(){
	int n;
	scanf("%d", &n);
	stack<int> s;
	int last_pushed = 0;
	char push_or_pop[200001];
	int ind = 0;
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		while(last_pushed < x){
			++last_pushed;
			s.push(last_pushed);
			push_or_pop[ind] = '+';
			++ind;
		}
		int tmp = s.top();
		if(tmp == x){
			s.pop();
			push_or_pop[ind] = '-';
			++ind;
		}else{
			printf("NO");
			return 0;
		}
	}
	for(int i = 0; i < 2*n; ++i){
		printf("%c\n", push_or_pop[i]);
	}
	return 0;
}
