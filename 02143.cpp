#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	long long t;
	scanf("%lld", &t);
	unsigned n;
	scanf("%u", &n);
	vector<int> a(n, 0);
	for(unsigned i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	unsigned m;
	scanf("%u", &m);
	vector<int> b(m, 0);
	for(unsigned j = 0; j < m; ++j){
		scanf("%d", &b[j]);
	}
	vector<long long> sum_a, sum_b;
	for(unsigned i = 0; i < n; ++i){
		long long sum = 0;
		for(unsigned j = i; j < n; ++j){
			sum += a[j];
			sum_a.push_back(sum);
		}
	}
	sort(sum_a.begin(), sum_a.end());
	for(unsigned i = 0; i < m; ++i){
		long long sum = 0;
		for(unsigned j = i; j < m; ++j){
			sum += b[j];
			sum_b.push_back(sum);
		}
	}
	sort(sum_b.begin(), sum_b.end());
	long long ans = 0;
	for(unsigned i = 0; i < sum_a.size(); ++i){
		auto low = lower_bound(sum_b.begin(), sum_b.end(), t - sum_a[i]) - sum_b.begin();
		auto high = upper_bound(sum_b.begin(), sum_b.end(), t - sum_a[i]) - sum_b.begin();
		ans += high - low;
	}
	printf("%lld", ans);
	return 0;
}
