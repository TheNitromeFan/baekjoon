#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> v;
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		v.push_back(make_pair(i, x));
	}
	int idx = 0;
	while(true){
		printf("%d ", v[idx].first);
		int move = v[idx].second;
		if(move > 0){
			--move;
		}
		v.erase(v.begin() + idx);
		--n;
		if(n == 0){
			break;
		}
		idx += move;
		while(idx < 0){
			idx += n;
		}
		idx %= n;
	}
	return 0;
}
