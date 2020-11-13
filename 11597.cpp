#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> s(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &s[i]);
	}
	sort(s.begin(), s.end());
	int x = 2000001;
	for(int i = 0, j = n - 1; i < j; ++i, --j){
		if(x > s[i] + s[j]){
			x = s[i] + s[j];
		}
	}
	printf("%d", x);
	return 0;
}
