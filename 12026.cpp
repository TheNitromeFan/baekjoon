#include <cstdio>
#include <cstring>

int main(){
	int n;
	scanf("%d", &n);
	char boj[1001];
	scanf("%s", boj);
	int energy[1001];
	memset(energy, -1, sizeof(energy));
	energy[0] = 0;
	for(int i = 0; i < n; ++i){
		if(energy[i] == -1){
			continue;
		}
		for(int j = i + 1; j < n; ++j){
			if(((boj[i] == 'B' && boj[j] == 'O')
			|| (boj[i] == 'O' && boj[j] == 'J')
			|| (boj[i] == 'J' && boj[j] == 'B'))
			&& (energy[j] == -1 || energy[j] > energy[i] + (j - i) * (j - i))){
				energy[j] = energy[i] + (j - i) * (j - i);
			}
		}
	}
	printf("%d", energy[n - 1]);
	return 0;
}
