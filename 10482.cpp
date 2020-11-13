#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#define MAX 32000

using namespace std;

void sieve(bool pr[MAX]){
	memset(pr, true, MAX * sizeof(bool));
	pr[0] = false;
	pr[1] = false;
	for(int p = 2; p * p < MAX; ++p){
		if(!pr[p]){
			continue;
		}
		for(int m = p; m * p < MAX; ++m){
			pr[m * p] = false;
		}
	}
}

int main(){
	bool prime[MAX];
	sieve(prime);
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		int ans = 0;
		vector<pair<int, int>> pairs;
		for(int i = 2, j = n - 2; i <= j; ++i, --j){
			if(prime[i] && prime[j]){
				++ans;
				pairs.push_back(make_pair(i, j));
			}
		}
		printf("%d has %d representation(s)\n", n, ans);
		for(auto p : pairs){
			printf("%d+%d\n", p.first, p.second);
		}
		printf("\n");
	}
	return 0;
}
