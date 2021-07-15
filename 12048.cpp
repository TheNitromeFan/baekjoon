#include <iostream>
#define MAX 200001

using namespace std;

long long sums_less_than(long long a[MAX], int n, long long cmp){
	long long ret = 0;
	int i = 1, j = 1;
	long long running_sum = 0;
	while(i <= n){
		while(j <= n && running_sum + a[j] <= cmp){
			running_sum += a[j];
			++j;
		}
		ret += j - i;
		running_sum -= a[i];
		++i;
	}
	return ret;
}

long long find_threshold_sum(long long psum[MAX], long long a[MAX], int n, long long k){
	long long low = 0, high = psum[n];
	while(low < high){
		long long mid = (low + high) / 2;
		if(sums_less_than(a, n, mid) >= k){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	return high;
}

long long sum_of_sums(long long qsum[MAX], long long psum[MAX], long long a[MAX], int n, long long k){
	long long thres = find_threshold_sum(psum, a, n, k);
	long long ret = 0;
	int i = 1, j = 1;
	long long running_sum = 0;
	while(i <= n){
		while(j <= n && running_sum + a[j] <= thres){
			running_sum += a[j];
			++j;
		}
		ret += qsum[j - 1] - qsum[i - 1] - (n - j + 1) * (psum[j - 1] - psum[i - 1]);
		running_sum -= a[i];
		++i;
	}
	ret -= thres * (sums_less_than(a, n, thres) - k);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n, q;
		cin >> n >> q;
		long long a[MAX];
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
		}
		long long psum[MAX] = {};
		long long qsum[MAX] = {};
		for(int i = 1; i <= n; ++i){
			psum[i] = psum[i - 1] + a[i];
			qsum[i] = qsum[i - 1] + (n + 1 - i) * a[i];
		}
		cout << "Case #" << a0 << ":\n";
		for(int a1 = 0; a1 < q; ++a1){
			long long left, right;
			cin >> left >> right;
			cout << sum_of_sums(qsum, psum, a, n, right) - sum_of_sums(qsum, psum, a, n, left - 1) << '\n';
		}
	}
	return 0;
}
