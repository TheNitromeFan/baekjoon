#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	queue<pair<int, int>> q;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		q.push(make_pair(i, x));
	}
	int time = 0;
	vector<int> ans(n, 0);
	while(!q.empty()){
		++time;
		pair<int, int> next = q.front();
		q.pop();
		int i = next.first, x = next.second;
		if(x > 1){
			q.push(make_pair(i, x - 1));
		}else{
			ans[i] = time;
		}
	}
	for(int i = 0; i < n; ++i){
		printf("%d ", ans[i]);
	}
	return 0;
}
