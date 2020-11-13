#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n, len;
	scanf("%d %d", &n, &len);
	vector<int> fruits(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &fruits[i]);
	}
	sort(fruits.begin(), fruits.end(), greater<int>());
	while(!fruits.empty() && fruits.back() <= len){
		fruits.pop_back();
		++len;
	}
	printf("%d", len);
	return 0;
}
