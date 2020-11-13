#include <cstdio>
#include <vector>

using std::vector;

void remove_round(vector<int> &v, int r){
	vector<int> w;
	for(unsigned i = 0; i < v.size(); ++i){
		if((i + 1) % r != 0){
			w.push_back(v[i]);
		}
	}
	v = w;
}

int main(){
	int k;
	int m;
	scanf("%d %d", &k, &m);
	vector<int> v(k);
	for(int i = 1; i <= k; ++i){
		v[i - 1] = i;
	}
	for(int a0 = 0; a0 < m; ++a0){
		int r;
		scanf("%d", &r);
		remove_round(v, r);
	}
	for(int x : v){
		printf("%d\n", x);
	}
	return 0;
}
