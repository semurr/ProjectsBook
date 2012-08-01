//guess my number game
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//constant
	const int ci_max_number = 100;

	//variables
	int i_tries = 0;
	int i_rand_num = 0;
	int i_guess;

	//seed random gen
	srand((unsigned)time(0));

	//set the random number

	i_rand_num = rand() % ci_max_number;

	cout << " Welcome to guess the number! ";
	cout <<" The number is between 0 and " << ci_max_number << endl << endl;

	//output
	do
	{
		cout << "What is your guess?: ";
		cin >> i_guess;

		if(i_guess > i_rand_num)
		{
			cout << "Your guess was to high!" << endl;
			i_tries++;
		}
		
		if(i_guess < i_rand_num)
		{
			cout << "Your guess was to low!" << endl;
			i_tries++;
		}



	}while (i_guess != i_rand_num);

	cout << "Congrats you guessed correctly" << endl;
	cout << "It took you " << i_tries << " to guess the correct number"; 

	return 0;
}