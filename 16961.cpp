#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int s[367] = {}, t[367] = {};
	int longestStay = -1;
	for(int i = 0; i < n; ++i){
		char c;
		int start, end;
		scanf(" %c %d %d", &c, &start, &end);
		if(c == 'S'){
			for(int j = start; j <= end; ++j){
				++s[j];
			}
		}else{
			for(int j = start; j <= end; ++j){
				++t[j];
			}
		}
		int len = end - start + 1;
		if(len > longestStay){
			longestStay = len;
		}
	}
	int daysWithGuest = 0, mostGuests = 0, daysWithoutFights = 0, mostGuestsWithoutFights = 0;
	for(int day = 1; day <= 366; ++day){
		if(s[day] + t[day] > 0){
			++daysWithGuest;
		}
		if(s[day] + t[day] > mostGuests){
			mostGuests = s[day] + t[day];
		}
		if(s[day] > 0 && s[day] == t[day]){
			++daysWithoutFights;
		}
		if(s[day] > 0 && s[day] == t[day] && s[day] + t[day] > mostGuestsWithoutFights){
			mostGuestsWithoutFights = s[day] + t[day];
		}
	}
	printf("%d\n%d\n%d\n%d\n%d", daysWithGuest, mostGuests, daysWithoutFights, mostGuestsWithoutFights, longestStay);
	return 0;
}
