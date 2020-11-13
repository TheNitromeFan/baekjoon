#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> ans;
	for(int a0 = 0; a0 < n;+ ++a0){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int g = gcd(abs(a), abs(c));
		ans.clear();
		for(int i = -g; i <= g; ++i){
			for(int j = -(abs(g) - abs(i)); j <= abs(g) - abs(i); ++j){
				if(i * i + j * j == g * g){
					ans.push_back(make_pair(i, j));
				}
			}
		}
		printf("%d\n", ans.size());
		for(auto p : ans){
			printf("%d %d ", p.first, p.second);
		}
		printf("\n");
	}
	return 0;
}
