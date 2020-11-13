#include <iostream>

#include <string>

using namespace std;



const int MAX = 31;



string s, input;

int dollar, nonDollar;

int repeat, start, finish;

//cache[i] = i�� �ݺ����� �� ����

long long cache[MAX]; //2 ^ 30 = 1,073,741,824

bool found;



void searchChar(int level, int idx) //level = �ݺ� Ƚ��

{

        long long pos = 0;

        for (long long i = 0; !found && i < input.length(); i++)

        {

                 if (input[i] == '$')

                 {

                         //�ݺ� Ƚ�� �������� ����

                         if (level == 1)

                         {

                                 if (idx <= pos + cache[level] - 1)

                                 {

                                          found = true;

                                          cout << s[idx - pos];

                                 }

                                 else

                                          pos += cache[level];

                         }

                         else if (level > 1)

                         {

                                 if (idx <= pos + cache[level] - 1)

                                          searchChar(level - 1, idx - pos);

                                 else

                                          pos += cache[level];

                         }

                 }

                 else

                 {

                         if (pos == idx)

                         {

                                 found = true;

                                 cout << input[i];

                                 return;

                         }

                         else

                                 pos++;

                 }

        }

}



int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        cin >> s >> input >> repeat >> start >> finish;



        for (long long i = 0; i < input.length(); i++)

                 if (input[i] == '$')

                         dollar++;

                 else

                         nonDollar++;



        //$�� �ϳ��̸� ���̰� õõ�� �����Ͽ� ���� ó��

        if (dollar < 2)

        {

                 for (int i = start - 1; i < finish; i++)

                         if (i < s.length())

                                 cout << s[i];

                         else if (i >= s.length() + (input.length() - 1) * repeat)

                                 cout << "-";

                         //s.length() <= i < s.length() + (input.length() -1) * repeat

                         else

                                 cout << input[(i - s.length()) % (input.length() - 1) + 1];

                 cout << "\n";

        }

        //$�� 2�������̸� ���� ����Ͽ� �����ϹǷ� ���߿� �ߴ� ����

        else

        {

                 cache[1] = s.length();

                 for (int i = 2; i <= repeat; i++)

                 {

                         cache[i] = cache[i - 1] * dollar + nonDollar;

                         //���ϰ��� �ϴ� �ε��� ������ �ʰ��� break

                         if (cache[i] > finish)

                         {

                                 repeat = i;

                                 break;

                         }

                 }



                 for (int i = start - 1; i < finish; i++)

                 {

                         int temp = repeat;

                         //���� �ʰ���

                         if (i >= cache[temp] * dollar + nonDollar)

                         {

                                 cout << "-";

                                 continue;

                         }



                         while (temp > 1 && cache[temp] > i)

                                 temp--;



                         found = false;

                         searchChar(temp, i);

                 }

                 cout << "\n";

        }

        return 0;

}


