#include <cstdio>
#include <cmath>

struct scores{
	double a;
	double b;
	double c;
	int p;
	bool running;
} events[7];

int main(){
	events[0].a = 9.23076;
	events[0].b = 26.7;
	events[0].c = 1.835;
	events[0].running = true;
	events[1].a = 1.84523;
	events[1].b = 75;
	events[1].c = 1.348;
	events[1].running = false;
	events[2].a = 56.0211;
	events[2].b = 1.5;
	events[2].c = 1.05;
	events[2].running = false;
	events[3].a = 4.99087;
	events[3].b = 42.5;
	events[3].c = 1.81;
	events[3].running = true;
	events[4].a = 0.188807;
	events[4].b = 210;
	events[4].c = 1.41;
	events[4].running = false;
	events[5].a = 15.9803;
	events[5].b = 3.8;
	events[5].c = 1.04;
	events[5].running = false;
	events[6].a = 0.11193;
	events[6].b = 254;
	events[6].c = 1.88;
	events[6].running = true;
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int score = 0;
		for(int j = 0; j < 7; ++j){
			scanf("%d", &events[j].p);
			if(events[j].running){
				score += floor(events[j].a * pow(events[j].b - events[j].p, events[j].c));
			}else{
				score += floor(events[j].a * pow(events[j].p - events[j].b, events[j].c));
			}
		}
		printf("%d\n", score);
	}
	return 0;
}
