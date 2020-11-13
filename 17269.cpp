#include <cstdio>

int val(char c){
	int ret = 1;
	switch(c){
		case 'B':
		case 'D':
		case 'N':
		case 'P':
		case 'Q':
		case 'R':
		case 'T':
		case 'X':
		case 'Y':
			ret = 2;
			break;
		case 'A':
		case 'F':
		case 'H':
		case 'K':
		case 'M':
			ret = 3;
			break;
		case 'E':
			ret = 4;
			break;
	}
	return ret;
}

int main(){
	int n, m;
	char name1[101], name2[101];
	scanf("%d %d", &n, &m);
	scanf("%s %s", name1, name2);
	int a[200];
	int i = 0, j = 0, pos = 0;
	while(i < n || j < m){
		if(i < n){
			a[pos] = val(name1[i]);
			++i;
			++pos;
		}
		if(j < m){
			a[pos] = val(name2[j]);
			++j;
			++pos;
		}
	}
	for(int len = n + m; len > 2; --len){
		for(int idx = 0; idx + 1 < len; ++idx){
			a[idx] = (a[idx] + a[idx + 1]) % 10;
		}
	}
	printf("%d%%", 10 * a[0] + a[1]);
	return 0;
}
