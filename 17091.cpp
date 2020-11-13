#include <cstdio>
#include <string>
#include <vector>

using std::string;
using std::vector;

vector<string> hours = {"twelve", "one", "two", "three", "four", "five",
						 "six", "seven", "eight", "nine", "ten", "eleven", "twelve"};

vector<string> minutes = {"", "one", "two", "three", "four", "five",
						"six", "seven", "eight", "nine", "ten", "eleven",
						"twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
						"eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three",
						"twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"};

int main(){
	int h, m;
	scanf("%d %d", &h, &m);
	if(m == 0){
		printf("%s o' clock", hours[h].c_str());
	}else if(m == 30){
		printf("half past %s", hours[h].c_str());
	}else if(m == 15){
		printf("quarter past %s", hours[h].c_str());
	}else if(m == 45){
		printf("quarter to %s", hours[(h + 1) % 12].c_str());
	}else if(m == 1){
		printf("one minute past %s", hours[h].c_str());
	}else if(m == 59){
		printf("one minute to %s", hours[(h + 1) % 12].c_str());
	}else if(m <= 30){
		printf("%s minutes past %s", minutes[m].c_str(), hours[h].c_str());
	}else{
		printf("%s minutes to %s", minutes[60 - m].c_str(), hours[(h + 1) % 12].c_str());
	}
	return 0;
}
