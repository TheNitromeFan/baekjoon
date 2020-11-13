#include <cstdio>
#define MAX 100

struct light{
	int dist;
	int red;
	int green;
} lights[MAX];

int main(){
	int n, len;
	scanf("%d %d", &n, &len);
	for(int i = 0; i < n; ++i){
		scanf("%d %d %d", &lights[i].dist, &lights[i].red, &lights[i].green);
	}
	int time = -1;
	int pos = 0;
	int light_index = 0;
	while(pos < len){
		++time;
		if(light_index < n && lights[light_index].dist == pos){
			if(time % (lights[light_index].red + lights[light_index].green) < lights[light_index].red){
				continue;
			}else{
				++light_index;
			}
		}
		++pos;
	}
	printf("%d", time + 1);
	return 0;
}
