#include <cstdio>
#include <vector>
#define MAX 101

using namespace std;

int main(){
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		char sol[MAX][MAX];
		for(int i = 0; i < n; ++i){
			scanf("%s", sol[i]);
		}
		for(int i = 0; i < n; ++i){
			int cnt = 0;
			vector<int> ans;
			for(int j = 0; j < n; ++j){
				if(sol[i][j] == '.'){
					if(cnt > 0){
						ans.push_back(cnt);
					}
					cnt = 0;
				}else{
					++cnt;
				}
			}
			if(cnt > 0){
				ans.push_back(cnt);
			}
			if(ans.empty()){
				ans.push_back(0);
			}
			for(int x : ans){
				printf("%d ", x);
			}
			printf("\n");
		}
		for(int j = 0; j < n; ++j){
			int cnt = 0;
			vector<int> ans;
			for(int i = 0; i < n; ++i){
				if(sol[i][j] == '.'){
					if(cnt > 0){
						ans.push_back(cnt);
					}
					cnt = 0;
				}else{
					++cnt;
				}
			}
			if(cnt > 0){
				ans.push_back(cnt);
			}
			if(ans.empty()){
				ans.push_back(0);
			}
			for(int x : ans){
				printf("%d ", x);
			}
			printf("\n");
		}
	}
	return 0;
}
