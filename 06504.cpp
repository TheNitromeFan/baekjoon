#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> fibs = {1, 2};
	while(fibs[fibs.size() - 1] < 50000){
		fibs.push_back(fibs[fibs.size() - 1] + fibs[fibs.size() - 2]);
	}
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		scanf("%d", &n);
		vector<unsigned> binary;
		for(unsigned i = 0; i < fibs.size(); ++i){
			if(n >= fibs[fibs.size() - 1 - i]){
				binary.push_back(fibs.size() - 1 - i);
				n -= fibs[fibs.size() - 1 - i];
			}
		}
		int m = 0;
		for(unsigned x : binary){
			if(x > 0){
				m += fibs[x - 1];
			}
		}
		printf("%d\n", m);
	}
	return 0;
}
