#include <cstdio>
#include <vector>

using std::vector;

int main(){
	int w, p;
	scanf("%d %d", &w, &p);
	vector<int> parts = {0};
	for(int i = 0; i < p; ++i){
		int x;
		scanf("%d", &x);
		parts.push_back(x);
	}
	parts.push_back(w);
	vector<bool> space(w + 1, false);
	for(int i = 0; i < p + 2; ++i){
		for(int j = 0; j < i; ++j){
			space[parts[i] - parts[j]] = true;
		}
	}
	for(int len = 1; len <= w; ++len){
		if(space[len]){
			printf("%d ", len);
		}
	}
	return 0;
}
