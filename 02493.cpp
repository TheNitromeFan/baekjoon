#include <cstdio>
#include <stack>
#include <utility>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	stack<pair<int, int>> s;
	for(int i = 1; i <= n; ++i){
		int height;
		scanf("%d", &height);
		while(!s.empty()){
			pair<int, int> cmp = s.top();
			if(cmp.first > height){
				printf("%d ", cmp.second);
				break;
			}
			s.pop();
		}
		if(s.empty()){
			printf("0 ");
		}
		s.push(make_pair(height, i));
	}
	return 0;
}
