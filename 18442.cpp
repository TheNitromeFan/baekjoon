#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define MAX 20

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v, p;
	long long l;
	cin >> v >> p >> l;
	long long a[MAX];
	for(int i = 0; i < v; ++i){
		cin >> a[i];
	}
	vector<int> bitmask(p, 1);
	bitmask.resize(v);
	long long ans = 4000000000000000000LL;
	vector<int> post = bitmask;
	do{
		long long cmp = 0;
		for(int i = 0; i < v; ++i){
			long long dist = 4000000000000000000LL;
			for(int j = 0; j < v; ++j){
				if(bitmask[j]){
					dist = min(dist, min(llabs(a[i] - a[j]), l - llabs(a[i] - a[j])));
				}
			}
			cmp += dist;
		}
		if(cmp < ans){
			ans = cmp;
			post = bitmask;
		}
	}while(prev_permutation(bitmask.begin(), bitmask.end()));
	cout << ans << '\n';
	for(int i = 0; i < v; ++i){
		if(post[i]){
			cout << a[i] << ' ';
		}
	}
	return 0;
}
