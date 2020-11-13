#include <cstdio>
#include <algorithm>

using std::max;

int main(){
	int n;
	scanf("%d", &n);
	int stairs[301];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &stairs[i]);
	}
	if(n == 1){
		printf("%d", stairs[1]);
		return 0;
	}
	int maximum[301][2] = {};
    maximum[1][0] = stairs[1];
    maximum[2][0] = stairs[2];
    maximum[2][1] = maximum[1][0] + stairs[2];
	for(int i = 3; i <= n; i++){
        maximum[i][0] = max(maximum[i-2][0], maximum[i-2][1]) + stairs[i];
        maximum[i][1] = maximum[i-1][0] + stairs[i];
    }
    printf("%d", max(maximum[n][0], maximum[n][1]));
    return 0;
}
