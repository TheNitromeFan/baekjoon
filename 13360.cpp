#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int rank = 25, stars = 0;
	string games;
	cin >> games;
	int consec = 0;
	for(char c : games){
		if(c == 'W'){
			++consec;
			bool bonus = (rank >= 6 && consec >= 3);
			if(rank >= 21 && rank <= 25 && stars == 2){
				--rank;
				stars = 1;
			}else if(rank >= 16 && rank <= 20 && stars == 3){
				--rank;
				stars = 1;
			}else if(rank >= 11 && rank <= 15 && stars == 4){
				--rank;
				stars = 1;
			}else if(rank >= 1 && rank <= 10 && stars == 5){
				--rank;
				stars = 1;
			}else{
				++stars;
			}
			if(!bonus){
				continue;
			}
			if(rank >= 21 && rank <= 25 && stars == 2){
				--rank;
				stars = 1;
			}else if(rank >= 16 && rank <= 20 && stars == 3){
				--rank;
				stars = 1;
			}else if(rank >= 11 && rank <= 15 && stars == 4){
				--rank;
				stars = 1;
			}else if(rank >= 1 && rank <= 10 && stars == 5){
				--rank;
				stars = 1;
			}else{
				++stars;
			}
		}else{
			consec = 0;
			if(rank >= 21){
				continue;
			}
			if(rank >= 1 && rank <= 9 && stars == 0){
				++rank;
				stars = 4;
			}else if(rank >= 10 && rank <= 14 && stars == 0){
				++rank;
				stars = 3;
			}else if(rank >= 15 && rank <= 19 && stars == 0){
				++rank;
				stars = 2;
			}else if(stars > 0){
				--stars;
			}
		}
	}
	if(rank > 0){
		cout << rank;
	}else{
		cout << "Legend";
	}
	return 0;
}
