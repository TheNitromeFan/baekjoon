#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> w(n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &w[i]);
	}
	sort(w.begin(), w.end());
	int sum = 0;
	for(int i = 0; i < n; ++i){
		if(sum + 1 < w[i]){
			break;
		}
		sum += w[i];
	}
	printf("%d", sum + 1);
	return 0;
}
