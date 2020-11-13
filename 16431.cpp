#include <cstdio>
#include <algorithm>

int dist1(int x1, int y1, int x2, int y2){
	return std::max(abs(x1 - x2), abs(y1 - y2));
}

int dist2(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
	int br, bc, dr, dc, jr, jc;
	scanf("%d %d %d %d %d %d", &br, &bc, &dr, &dc, &jr, &jc);
	int d1 = dist1(br, bc, jr, jc), d2 = dist2(dr, dc, jr, jc);
	if(d1 < d2){
		printf("bessie");
	}else if(d1 > d2){
		printf("daisy");
	}else{
		printf("tie");
	}
	return 0;
}
