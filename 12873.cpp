#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		v[i] = i + 1;
	}
	for(int level = 1; level < n; ++level){
		long long rotations = (long long)level * level * level - 1;
		rotations %= n - level + 1;
		rotate(v.begin(), v.begin() + rotations, v.end());
		v.erase(v.begin());
	}
	printf("%d", v[0]);
	return 0;
}
