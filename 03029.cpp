#include <cstdio>

int main(){
	int nowh, nowm, nows, sodiumh, sodiumm, sodiums;
	scanf("%d:%d:%d\n%d:%d:%d", &nowh, &nowm, &nows, &sodiumh, &sodiumm, &sodiums);
	int now = nowh * 60 * 60 + nowm * 60 + nows;
	int sodium = sodiumh * 60 * 60 + sodiumm * 60 + sodiums;
	if(sodium <= now){
		sodium += 24 * 60 * 60;
	}
	int diff = sodium - now;
	int diffh = diff / 60 / 60, diffm = (diff / 60) % 60, diffs = diff % 60;
	if(diffh < 10){
		printf("0");
	}
	printf("%d", diffh);
	printf(":");
	if(diffm < 10){
		printf("0");
	}
	printf("%d", diffm);
	printf(":");
	if(diffs < 10){
		printf("0");
	}
	printf("%d", diffs);
	return 0;
}
