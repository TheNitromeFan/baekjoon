#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, len;
	scanf("%d %d", &n, &len);
	vector<int> holes(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &holes[i]);
	}
	sort(holes.begin(), holes.end());
	int pos = holes[0];
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(holes[i] >= pos){
			++cnt;
			pos = holes[i] + len;
		}
	}
	printf("%d", cnt);
	return 0;
}
