#include <cstdio>
#include <utility>
#include <stack>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	stack<pair<int, int>> s;
	long long points = 0;
	for(int i = 0; i < n; ++i){
		int a;
		scanf("%d", &a);
		if(a){
			int p, t;
			scanf("%d %d", &p, &t);
			s.push(make_pair(p, t));
		}
		if(!s.empty()){
			auto work = s.top();
			s.pop();
			--work.second;
			if(work.second == 0){
				points += work.first;
			}else{
				s.push(work);
			}
		}
	}
	printf("%lld", points);
	return 0;
}
