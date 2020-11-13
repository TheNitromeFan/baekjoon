#include <cstdio>
#include <vector>
#include <tuple>
#define MAX (1 << 24)

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<tuple<int, int, int>> edges;
	for(int e = 0; e < m; ++e){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		bool duplicate = false;
		for(int i = 0; i < e; ++i){
			tuple<int, int, int> tmp;
			if(get<0>(tmp) == a && get<1>(tmp) == b){
				duplicate = true;
				if(get<2>(tmp) > c){
					edges[i] = make_tuple(a, b, c);
				}
				break;
			}
		}
		if(!duplicate){
			edges.push_back(make_tuple(a, b, c));
		}
	}
	long long dist[501];
	dist[1] = 0;
	for(int v = 2; v <= n; ++v){
		dist[v] = MAX;
	}
	for(int i = 1; i < n; ++i){
		for(tuple<int, int, int> edge : edges){
			int u = get<0>(edge);
			int v = get<1>(edge);
			int w = get<2>(edge);
			if(dist[u] != MAX && dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
			}
		}
	}
	for(tuple<int, int, int> edge : edges){
		int u = get<0>(edge);
		int v = get<1>(edge);
		int w = get<2>(edge);
		if(dist[u] != MAX && dist[u] + w < dist[v]){
			printf("-1");
			return 0;
		}
	}
	for(int v = 2; v <= n; ++v){
		printf("%lld\n", (dist[v] == MAX ? -1 : dist[v]));
	}
	return 0;
}
