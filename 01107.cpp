#include <cstdio>
#include <cstdlib>

int min;

bool broken[11];

void find(int channel, int num, int length){
	for(int i = 0; i < 10; ++i){
		if(!broken[i]){
			int tmp = num * 10 + i;
			int cmp = abs(channel - tmp) + length + 1;
			if(min > cmp){
				min = cmp;
			}
			if(length < 6){
				find(channel, tmp, length + 1);
			}
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	min = abs(n - 100);
	for(int i = 0; i < m; ++i){
		int button;
		scanf("%d", &button);
		broken[button] = true;
	}
	find(n, 0, 0);
	printf("%d", min);
	return 0;
}
