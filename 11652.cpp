#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<long long, int> cnt;

bool cmp(long long x, long long y){
	return cnt[x] > cnt[y] || (cnt[x] == cnt[y] && x < y);
}

int main(){
	int n;
	scanf("%d", &n);
	vector<long long> v;
	for(int i = 0; i < n; ++i){
		long long x;
		scanf("%lld", &x);
		if(cnt.find(x) == cnt.end()){
			cnt[x] = 1;
			v.push_back(x);
		}else{
			++cnt[x];
		}
	}
	sort(v.begin(), v.end(), cmp);
	printf("%lld", v[0]);
	return 0;
}
