#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int prev = 0;
	vector<int> ans;
	for(int i = 0; i < n; ++i){
		int cur;
		scanf("%d", &cur);
		while(cur - prev > 1){
			++prev;
			ans.push_back(prev);
		}
		prev = cur;
	}
	if(!ans.empty()){
		for(int x : ans){
			printf("%d\n", x);
		}
	}else{
		printf("good job");
	}
	return 0;
}
