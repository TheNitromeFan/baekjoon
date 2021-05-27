#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<long long, long long>> cache;

int n0 = -1;

void preprocess(long long n){
	n0 = n;
	cache.push_back(make_pair(0, 0));
	long long x = 0;
	for(long long i = 1, j = 0; i <= n; i = j + 1){
		j = n / (n / i);
		x += (j - i + 1) * (n / i);
		cache.push_back(make_pair(j, x));
	}
}

unsigned find_index(long long end){
	unsigned low = 0, high = cache.size() - 1;
	while(low < high){
		unsigned mid = (low + high) / 2;
		if(cache[mid].first <= end){
			low = mid + 1;
		}else{
			high = mid;
		}
	}
	return low - 1;
}

long long f(long long n, long long end){
	if(end > n){
		end = n;
	}
	if(n == n0){
		unsigned idx = find_index(end);
		long long j = cache[idx].first, ret = cache[idx].second;
		if(j == end){
			return ret;
		}
		long long i = j + 1;
		j = n / (n / i);
		if(j > end){
			j = end;
		}
		ret += (j - i + 1) * (n / i);
		return ret;
	}
	long long ret = 0;
	for(long long i = 1, j = 0; i <= n && i <= end; i = j + 1){
		j = n / (n / i);
		if(j > end){
			j = end;
		}
		ret += (j - i + 1) * (n / i);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	for(int a0 = 0; a0 < q; ++a0){
		long long n, s, e;
		cin >> n >> s >> e;
		if(n0 == -1){
			preprocess(n);
		}
		if(s > e){
			cout << 0 << '\n';
			continue;
		}
		cout << f(n, e) - f(n, s - 1) << '\n';
	}
	return 0;
}
