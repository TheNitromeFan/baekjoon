#include <cstdio>
#include <vector>

using namespace std;

bool all_same(vector<int> &c){
	for(unsigned idx = 1; idx < c.size(); ++idx){
		if(c[0] != c[idx]){
			return false;
		}
	}
	return true;
}

int cycles(vector<int> &c){
	int ret = 0;
	while(!all_same(c)){
		vector<int> pass(c.size(), 0);
		for(unsigned idx = 0; idx < c.size(); ++idx){
			pass[idx] = c[idx] / 2;
			c[idx] /= 2;
		}
		for(unsigned idx = 0; idx < c.size(); ++idx){
			c[(idx + 1) % c.size()] += pass[idx];
		}
		for(unsigned idx = 0; idx < c.size(); ++idx){
			if(c[idx] % 2){
				++c[idx];
			}
		}
		++ret;
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		vector<int> c(n, 0);
		for(int i = 0; i < n; ++i){
			scanf("%d", &c[i]);
			if(c[i] % 2){
				++c[i];
			}
		}
		printf("%d\n", cycles(c));
	}
	return 0;
}
