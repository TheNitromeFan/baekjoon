#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp1(tuple<int, int, int> a, tuple<int, int, int> b){
	return get<1>(a) > get<1>(b);
}

bool cmp2(tuple<int, int, int> a, tuple<int, int, int> b){
	return get<2>(a) > get<2>(b);
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<tuple<int, int, int>> cnd;
	cnd.resize(n);
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		cnd[i] = make_tuple(i + 1, a, b);
	}
	sort(cnd.begin(), cnd.end(), cmp1);
	sort(cnd.begin(), cnd.begin() + k, cmp2);
	printf("%d", get<0>(cnd[0]));
	return 0;
}
