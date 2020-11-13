#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int cranes[50];
	for(int i = 0; i < n; ++i){
		scanf("%d", &cranes[i]);
	}
	sort(cranes, cranes+n, greater<int>());
	int m;
	scanf("%d", &m);
	int cargo[10000];
	for(int j = 0; j < m; ++j){
		scanf("%d", &cargo[j]);
	}
	sort(cargo, cargo+m, greater<int>());
	if(cargo[0] > cranes[0]){
		printf("-1");
		return 0;
	}
	int time = 0;
	int cnt = m;
	bool moved[10000];
	for(int j = 0; j < m; ++j){
		moved[j] = false;
	}
	while(cnt){
		for(int i = 0; i < n; ++i){
			bool flag = true;
			for(int j = 0; j < m; ++j){
				if(!moved[j] && (cargo[j] <= cranes[i])){
					moved[j] = true;
					--cnt;
					flag = false;
					break;
				}
			}
			if(flag){
				--n;
			}
		}
		++time;
	}
	printf("%d", time);
	return 0;
}
