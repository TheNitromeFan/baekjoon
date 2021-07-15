#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> c(n + 1);
	for(int i = 1; i <= n; ++i){
		int x, y, s;
		cin >> x >> y >> s;
		c[i] = make_tuple(x, y, s);
	}
	vector<int> adj(n + 1);
	for(int i = 1; i <= n; ++i){
		int x = get<0>(c[i]), y = get<1>(c[i]), s0 = get<2>(c[i]);
		int s = -1, dist = -1, ans = -1;
		bool kingdom = true;
		bool democracy = false;
		for(int j = 1; j <= n; ++j){
			if(j == i){
				continue;
			}
			int x1 = get<0>(c[j]), y1 = get<1>(c[j]), s1 = get<2>(c[j]);
			int dist1 = (x - x1) * (x - x1) + (y - y1) * (y - y1);
			if((s == -1 && dist == -1) || (long long)s1 * dist > (long long)s * dist1){
				s = s1;
				dist = dist1;
				democracy = false;
				ans = j;
				if((long long)s1 > (long long)s0 * dist1){
					kingdom = false;
				}
			}else if((long long)s1 * dist == (long long)s * dist1){
				democracy = true;
			}
		}
		if(kingdom){
			adj[i] = i;
		}else if(democracy){
			adj[i] = 0;
		}else{
			adj[i] = ans;
		}
	}
	for(int i = 1; i <= n; ++i){
		if(adj[i] == i){
			cout << 'K' << '\n';
		}else if(adj[i] == 0){
			cout << 'D' << '\n';
		}else{
			int u = i;
			while(adj[u] != u && adj[u] != 0){
				u = adj[u];
			}
			cout << u << '\n';
		}
	}
	return 0;
}
