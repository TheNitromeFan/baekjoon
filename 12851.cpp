#include <cstdio>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	bool visited[200001] = {};
	int cnt = 0;
	int min_dist = -1;
	visited[n] = true;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int x = p.first, i = p.second;
		if(min_dist != -1 && i > min_dist){
			break;
		}
		visited[x] = true;
		// printf("%d\n", x);
		if(x == k && min_dist == -1){
			min_dist = i;
			++cnt;
		}else if(x == k && i == min_dist){
			++cnt;
		}
		if(x < k && !visited[2 * x]){
			q.push(make_pair(2 * x, i + 1));
		}
		if(!visited[x + 1]){
			q.push(make_pair(x + 1, i + 1));
		}
		if(x > 0 && !visited[x - 1]){
			q.push(make_pair(x - 1, i + 1));
		}
	}
	printf("%d\n%d", min_dist, cnt);
	return 0;
}
