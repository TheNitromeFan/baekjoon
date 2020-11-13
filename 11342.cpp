#include <iostream>
#include <string>

using namespace std;

int main(){
	string tmp;
	getline(cin, tmp);
	int n = tmp[0] - '0';
	for(int player = 0; player < n; ++player){
		int score = 0;
		string bowls;
		getline(cin, bowls);
		int frame = 1;
		bool pickup = false;
		int strike_bowl_count1 = 0, strike_bowl_count2 = 0, spare_bowl_count = 0;
		for(int i = 0; i < bowls.length(); i += 2){
			char roll = bowls[i];
			if(frame == 10){
				if(roll == 'X'){
					score += 10;
					if(strike_bowl_count1 > 0){
						score += 10;
						--strike_bowl_count1;
					}
					if(strike_bowl_count2 > 0){
						score += 10;
						--strike_bowl_count2;
					}
					if(spare_bowl_count > 0){
						score += 10;
						--spare_bowl_count;
					}
				}else if(roll == '/'){
					score += 10 - (bowls[i-2] - '0');
					if(strike_bowl_count1 > 0){
						score += 10 - (bowls[i-2] - '0');
						--strike_bowl_count1;
					}
					if(strike_bowl_count2 > 0){
						score += 10 - (bowls[i-2] - '0');
						--strike_bowl_count2;
					}
				}else{
					score += roll - '0';
					if(strike_bowl_count1 > 0){
						score += 10 - (bowls[i-2] - '0');
						--strike_bowl_count1;
					}
					if(strike_bowl_count2 > 0){
						score += 10 - (bowls[i-2] - '0');
						--strike_bowl_count2;
					}
					if(spare_bowl_count > 0){
					score += roll - '0';
					--spare_bowl_count;
					}
				}
				continue;
			}
			if(roll == 'X'){
				score += 10;
				if(strike_bowl_count1 > 0){
					score += 10;
					--strike_bowl_count1;
				}
				if(strike_bowl_count2 > 0){
					score += 10;
					--strike_bowl_count2;
				}
				if(spare_bowl_count > 0){
					score += 10;
					--spare_bowl_count;
				}
				if(strike_bowl_count1 == 0){
					strike_bowl_count1 = 2;
				}else{
					strike_bowl_count2 = 2;
				}
				++frame;
				pickup = false;
			}else if(roll == '/'){
				score += 10 - (bowls[i-2] - '0');
				if(strike_bowl_count1 > 0){
					score += 10 - (bowls[i-2] - '0');
					--strike_bowl_count1;
				}
				if(strike_bowl_count2 > 0){
					score += 10 - (bowls[i-2] - '0');
					--strike_bowl_count2;
				}
				spare_bowl_count = 1;
				++frame;
				pickup = false;
			}else{
				score += roll - '0';
				if(strike_bowl_count1 > 0){
					score += roll - '0';
					--strike_bowl_count1;
				}
				if(strike_bowl_count2 > 0){
					score += roll - '0';
					--strike_bowl_count2;
				}
				if(spare_bowl_count > 0){
					score += roll - '0';
					--spare_bowl_count;
				}
				if(pickup){
					++frame;
					pickup = false;
				}else{
					pickup = true;
				}
			}
		}
		cout << score << '\n';
	}
	return 0;
}
