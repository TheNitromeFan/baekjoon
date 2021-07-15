#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool transmit(vector<pair<long long, long long>> v, int n, long long d){
	long long low = v[0].first - d, high = v[0].first + d;
	for(int i = 1; i < n; ++i){
		if(v[i].first > v[i - 1].first){
			if(high + (v[i].second - v[i - 1].second) < v[i].first - d){
				return false;
			}
			high = min(v[i].first + d, high + (v[i].second - v[i - 1].second));
			low = v[i].first - d;
		}else{
			if(low - (v[i].second - v[i - 1].second) > v[i].first + d){
				return false;
			}
			low = max(v[i].first - d, low - (v[i].second - v[i - 1].second));
			high = v[i].first + d;
		}
	}
	return true;
}

int main(){
	int c;
	scanf("%d", &c);
	for(int a0 = 1; a0 <= c; ++a0){
		int n;
		scanf("%d", &n);
		vector<pair<long long, long long>> v(n);
		for(int i = 0; i < n; ++i){
			scanf("%lld %lld", &v[i].first, &v[i].second);
			v[i].first *= 2;
			v[i].second *= 2;
		}
		sort(v.begin(), v.end(), [](pair<long long, long long> a, pair<long long, long long> b){
			return a.second < b.second;
		});
		long long low = 0, high = 2000000000000000LL;
		while(low < high){
			long long mid = (low + high) / 2;
			if(transmit(v, n, mid)){
				high = mid;
			}else{
				low = mid + 1;
			}
		}
		printf("Case #%d: %lf\n", a0, high / 2.0);
	}
	return 0;
}
