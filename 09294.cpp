#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		printf("Case %d:\n", a0);
		int n, m, s;
		scanf("%d %d %d", &n, &m, &s);
		if(s < n || s > n * m){
			continue;
		}
		string bitmask(n - 1, 1);
		bitmask.resize(n - 1 + m - 1, 0);
		do{
			vector<int> v;
			int cnt = 0;
			int sum = 0;
			bool flag = true;
			for(int i = 0; i < n - 1 + m - 1; ++i){
				if(bitmask[i]){
					if(i + 1 - cnt > m){
						flag = false;
						break;
					}
					v.push_back(i + 1 - cnt);
					sum += i + 1 - cnt;
					++cnt;
				}
			}
			if(!flag){
				continue;
			}
			if(s - sum >= v[v.size() - 1] && s - sum <= m){
				printf("(");
				for(int j = 0; j < cnt; ++j){
					printf("%d,", v[j]);
				}
				printf("%d)\n", s - sum);
			}
		}while(prev_permutation(bitmask.begin(), bitmask.end()));
	}
	return 0;
}
