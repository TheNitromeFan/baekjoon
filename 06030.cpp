#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> factors(int n){
	vector<int> ret;
	int i;
	for(i = 1; i * i < n; ++i){
		if(n % i == 0){
			ret.push_back(i);
			ret.push_back(n / i);
		}
	}
	if(i * i == n){
		ret.push_back(i);
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main(){
	int p, q;
	scanf("%d %d", &p, &q);
	vector<int> x = factors(p), y = factors(q);
	for(int i : x){
		for(int j : y){
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}
