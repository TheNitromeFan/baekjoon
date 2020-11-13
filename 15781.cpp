#include <cstdio>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int helmet = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(x > helmet){
			helmet = x;
		}
	}
	int vest = 0;
	for(int j = 0; j < m; ++j){
		int y;
		scanf("%d", &y);
		if(y > vest){
			vest = y;
		}
	}
	printf("%d", helmet + vest);
	return 0;
}
