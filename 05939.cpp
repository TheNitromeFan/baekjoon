#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<tuple<int, int, int>> v;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d %d", &get<0>(v[i]), &get<1>(v[i]), &get<2>(v[i]));
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; ++i){
		printf("%d %d %d\n", get<0>(v[i]), get<1>(v[i]), get<2>(v[i]));
	}
	return 0;
}
