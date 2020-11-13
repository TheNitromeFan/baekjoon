#include <cstdio>
#include <vector>
#include <tuple>

using namespace std;

int main(){
	int test = 0;
	while(true){
		int n;
		scanf("%d", &n);
		if(n == 0){
			break;
		}
		++test;
		vector<tuple<int, int, int>> sols;
		for(int c = 2; 12 * n - 15 * c > 0; c += 2){
			if((2 * n + c) % 14 == 0){
				int a = (2 * n + c) / 14;
				int b = (12 * n - 15 * c) / 14;
				sols.push_back(make_tuple(a, b, c));
			}
		}
		printf("Case %d:\n%d pencils for %d cents\n", test, n, n);
		if(!sols.empty()){
			for(tuple<int, int, int> s : sols){
				printf("%d at four cents each\n%d at two for a penny\n%d at four for a penny\n\n",
				get<0>(s), get<1>(s), get<2>(s));
			}
		}else{
			printf("No solution found.\n\n");
		}
	}
	return 0;
}
