#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> p;
	p.resize(n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &p[i]);
	}
	int ind1 = n-1;
	while(ind1 > 0){
		if(p[ind1] > p[ind1-1]){
			--ind1;
		}else{
			break;
		}
	}
	if(ind1 == 0){
		printf("-1");
		return 0;
	}
	int ind2 = ind1;
	while(ind2 < n){
		if(p[ind2] < p[ind1-1]){
			++ind2;
		}else{
			break;
		}
	}
	swap(p[ind1-1], p[ind2-1]);
	for(int i = 0; i < ind1; ++i){
		printf("%d ", p[i]);
	}
	for(int i = ind1; i < n; ++i){
		printf("%d ", p[n+ind1-i-1]);
	}
	return 0;
}
