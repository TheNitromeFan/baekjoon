#include <cstdio>
#include <utility>

using namespace std;

int truthTellers(pair<int, int> p[1001], int n){
	for(int m = n; m >= 0; --m){
		int cnt = 0;
		for(int i = 1; i <= n; ++i){
			if(m >= p[i].first && m <= p[i].second){
				++cnt;
			}
		}
		if(cnt == m){
			return m;
		}
	}
	return -1;
}

int main(){
	int n;
	scanf("%d", &n);
	pair<int, int> p[1001];
	for(int i = 1; i <= n; ++i){
		scanf("%d %d", &p[i].first, &p[i].second);
	}
	printf("%d", truthTellers(p, n));
	return 0;
}
