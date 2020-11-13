#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool cmp(tuple<int, int, char> a, tuple<int, int, char> b){
	return get<1>(a) < get<1>(b) || (get<1>(a) == get<1>(b) && get<0>(a) < get<0>(b));
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<tuple<int, int, char>> v;
	v.resize(m);
	for(int i = 0; i < m; ++i){
		scanf("%d %d %c\n", &get<0>(v[i]), &get<1>(v[i]), &get<2>(v[i]));
	}
	sort(v.begin(), v.end(), cmp);
	for(auto t : v){
		printf("%c", get<2>(t));
	}
	return 0;
}
