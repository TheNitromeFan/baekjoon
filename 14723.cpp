#include <cstdio>
#include <utility>

using namespace std;

int main(){
	pair<int, int> fractions[2000];
	int ind = 1;
	for(int n = 1; n <= 45; ++n){
		for(int i = n; i >= 1; --i){
			fractions[ind] = make_pair(i, n+1-i);
			++ind;
		}
	}
	int n;
	scanf("%d", &n);
	printf("%d %d", fractions[n].first, fractions[n].second);
	return 0;
}
