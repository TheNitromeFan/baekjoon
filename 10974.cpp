#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v;
	for(int i = 1; i <= n; ++i){
		v.push_back(i);
	}
	do{
		for(vector<int>::size_type ind = 0; ind < v.size(); ++ind){
			printf("%d ", v[ind]);
		}
		printf("\n");
	}while(next_permutation(v.begin(), v.end()));
	return 0;
}
