#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;

void backtrack(vector<long long> &sums, map<pair<int, int>, long long> &a, vector<long long> &ans, int n, int sum_index, int i, int j){
	printf("%d %d %d\n", i, j, sum_index);
	/*
	for(auto x : ans){
		printf("%lld ", x);
	}
	printf("\n");
	*/
	if(ans.size() == n){
		vector<long long> b = ans;
		if(prev_permutation(b.begin(), b.end())){
			return;
		}
		/*
		for(int i = 0; i < n - 1; ++i){
			for(int j = i + 1; j < n; ++j){
				printf("(%d %d): %lld\n", i, j, a[make_pair(i, j)]);
			}
		}
		*/
		for(long long x : ans){
			printf("%lld ", x);
		}
		exit(0);
	}
	if(i == j || j == n){
		return;
	}
	a[make_pair(i, j)] = sums[sum_index];
	long long tmp;
	if(i == 0){
		backtrack(sums, a, ans, n, sum_index + 1, i + 1, j);
	}else if(i == 1){
		tmp = a[make_pair(0, 1)] + a[make_pair(0, 2)] - a[make_pair(1, 2)];
		if(tmp % 2 == 1){
			return;
		}
		ans.push_back(tmp / 2);
		tmp = a[make_pair(0, 1)] + a[make_pair(1, 2)] - a[make_pair(0, 2)];
		if(tmp % 2 == 1){
			return;
		}
		ans.push_back(tmp / 2);
		tmp = a[make_pair(0, 2)] + a[make_pair(1, 2)] - a[make_pair(0, 1)];
		if(tmp % 2 == 1){
			return;
		}
		ans.push_back(tmp / 2);
		backtrack(sums, a, ans, n, sum_index + 1, i + 1, j);
		ans.pop_back();
		ans.pop_back();
		ans.pop_back();
	}else{
		tmp = a[make_pair(0, i)] + a[make_pair(1, i)] - a[make_pair(0, 1)];
		if(tmp % 2 == 1){
			return;
		}
		ans.push_back(tmp / 2);
		backtrack(sums, a, ans, n, sum_index + 1, i + 1, j);
		ans.pop_back();
	}
	backtrack(sums, a, ans, n, sum_index + 1, i, j + 1);
}

int main(){
	int n;
	scanf("%d", &n);
	vector<long long> sums(n * (n - 1) / 2, 0);
	for(int i = 0; i < n * (n - 1) / 2; ++i){
		scanf("%lld", &sums[i]);
	}
	if(n == 2){
		printf("%lld", sums[0]);
		return 0;
	}
	sort(sums.begin(), sums.end());
	map<pair<int, int>, long long> a;
	vector<long long> ans;
	backtrack(sums, a, ans, n, 0, 0, 1);
	printf("Impossible");
	return 0;
}
