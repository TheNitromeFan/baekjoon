#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	unsigned n, m;
	scanf("%u %u", &n, &m);
	vector<unsigned> capacity(m + 1, 0);
	for(unsigned j = 1; j <= m; ++j){
		scanf("%u", &capacity[j]);
	}
	vector<vector<unsigned>> ans;
	ans.resize(n + 1);
	vector<vector<unsigned>> registered;
	registered.resize(m + 1);
	for(unsigned i = 1; i <= n; ++i){
		while(true){
			int subject;
			scanf("%d", &subject);
			if(subject == -1){
				break;
			}
			registered[subject].push_back(i);
		}
	}
	for(unsigned j = 1; j <= m; ++j){
		if(registered[j].size() <= capacity[j]){
			for(unsigned student : registered[j]){
				ans[student].push_back(j);
			}
			capacity[j] -= registered[j].size();
		}else{
			capacity[j] = 0;
		}
	}
	registered.clear();
	registered.resize(m + 1);
	for(unsigned i = 1; i <= n; ++i){
		while(true){
			int subject;
			scanf("%d", &subject);
			if(subject == -1){
				break;
			}
			registered[subject].push_back(i);
		}
	}
	for(unsigned j = 1; j <= m; ++j){
		if(registered[j].size() <= capacity[j]){
			for(unsigned student : registered[j]){
				ans[student].push_back(j);
			}
			capacity[j] -= registered[j].size();
		}else{
			capacity[j] = 0;
		}
	}
	for(unsigned i = 1; i <= n; ++i){
		if(ans[i].empty()){
			printf("¸ÁÇß¾î¿ä\n");
			continue;
		}
		sort(ans[i].begin(), ans[i].end());
		for(unsigned subject : ans[i]){
			printf("%u ", subject);
		}
		printf("\n");
	}
	return 0;
}
