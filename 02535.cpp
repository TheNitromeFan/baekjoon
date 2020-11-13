#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>
#include <functional>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<tuple<int, int, int>> v;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		scanf("%d %d %d", &get<1>(v[i]), &get<2>(v[i]), &get<0>(v[i]));
	}
	sort(v.begin(), v.end(), greater<tuple<int, int, int>>());
	printf("%d %d\n%d %d\n", get<1>(v[0]), get<2>(v[0]), get<1>(v[1]), get<2>(v[1]));
	int idx = 2;
	while(get<1>(v[0]) == get<1>(v[1]) && get<1>(v[0]) == get<1>(v[idx])){
		++idx;
	}
	printf("%d %d", get<1>(v[idx]), get<2>(v[idx]));
	return 0;
}
