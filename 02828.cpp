#include <cstdio>
#include <cstdlib>
#define MAX 20

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int j;
	scanf("%d", &j);
	int apples[MAX];
	for(int i = 0; i < j; ++i){
		scanf("%d", &apples[i]);
	}
	bool water[11] = {};
	int xmin = 1, xmax = m;
	for(int x = xmin; x <= xmax; ++x){
		water[x] = true;
	}
	int ans = 0;
	for(int i = 0; i < j; ++i){
		if(apples[i] > xmax){
			while(xmax < apples[i]){
				++xmax;
				water[xmax] = true;
				water[xmin] = false;
				++xmin;
				++ans;
			}
		}else if(apples[i] < xmin){
			while(xmin > apples[i]){
				--xmin;
				water[xmin] = true;
				water[xmax] = false;
				--xmax;
				++ans;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
