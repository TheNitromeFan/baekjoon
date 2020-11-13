#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int h, w;
	scanf("%d %d", &h, &w);
	if(h > w){
		swap(h, w);
	}
	printf("%.6f", max(min((double)h, w / 3.0), h / 2.0));
	return 0;
}
