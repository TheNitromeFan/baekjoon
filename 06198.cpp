#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}
	stack<int> s;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		while(!s.empty() && s.top() <= v[i]){
			s.pop();
		}
		ans += (long long)s.size();
		s.push(v[i]);
	}
	printf("%lld", ans);
	return 0;
}
