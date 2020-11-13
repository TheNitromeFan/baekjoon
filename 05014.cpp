#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int bfs(int sz, int start, int goal, int up, int down){
	queue<int> q;
	vector<int> presses(sz + 1, 0);
	q.push(start);
	while(!q.empty()){
		int pos = q.front();
		q.pop();
		if(pos == goal){
			return presses[pos];
		}
		int upos = pos + up;
		if(upos <= sz && upos != start && presses[upos] == 0){
			presses[upos] = presses[pos] + 1;
			q.push(upos);
		}
		int dpos = pos - down;
		if(dpos >= 1 && dpos != start && presses[dpos] == 0){
			presses[dpos] = presses[pos] + 1;
			q.push(dpos);
		}
	}
	return -1;
}

int main(){
	int f, s, g, u, d;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
	int ans = bfs(f, s, g, u, d);
	if(ans == -1){
		printf("use the stairs");
	}else{
		printf("%d", ans);
	}
	return 0;
}
