#include <cstdio>
#define MAX 9999

int main(){
	int c = 0;
	while(true){
		++c;
		int z, i, m, ell;
		scanf("%d %d %d %d", &z, &i, &m, &ell);
		if(z == 0 && i == 0 && m == 0 && ell == 0){
			break;
		}
		int visited[MAX+1] = {};
		visited[ell] = 1;
		int next;
		while(true){
			next = (z * ell + i) % m;
			if(visited[next] != 0){
				break;
			}
			visited[next] = visited[ell] + 1;
			ell = next;
		}
		printf("Case %d: %d\n", c, visited[ell] + 1 - visited[next]);
	}
	return 0;
}
