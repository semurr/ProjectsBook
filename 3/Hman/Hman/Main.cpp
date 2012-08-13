#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	//const variables
	const int ci_num_words = 6;
	const int ci_max_miss = 5;
	const string cs_words[ci_num_words] = 
	{
		"jump",
		"fire",
		"tower",
		"apple",
		"telephone",
		"infrastructure"
	};

	//variables
	int i_word_size;
	int i_miss = 0;
	int i_word_position;
	int i_correctGuess = 0;
	bool b_cGuess = false;
	srand((unsigned)time(0));
	char c_word[] = {"*"};
	char c_guess;
	
	//gather variable
	i_word_position = rand() % ci_num_words;
	i_word_size = cs_words[i_word_position].size();

	//set the word to display string
	for(int i = 0; i < i_word_size; i++)
	{
		c_word[i] = '*';
	}

	//todo remove later
	//debug output
	cout << "word using" << cs_words[i_word_position] << " Size " << cs_words[i_word_position].size() << endl;

	//main output
	cout << " Welcome to hang man" << endl;
	cout << " You have get a total of " << ci_max_miss << " misses guess wisely!(lowercase only)" << endl << endl;

	cout << " The word has " << i_word_size << " letters." << endl << endl;

	do
	{
		cout << " The word = ";  

		//display temp word
		for(int i = 0; i < i_word_size; i++)
		{
			cout << c_word[i];
		}
		
		//grab letter from user
		cout << endl << endl << "Please enter a letter: ";
		cin >> c_guess;

		//check if letter is correct then mark variable if true or not
		for(int i = 0; i < i_word_size; i++)
		{
			if(cs_words[i_word_position].at(i) == c_guess)
			{
				c_word[i] = c_guess;
				i_correctGuess++;
				b_cGuess = true;
			}
		}

		//check if user got the word if not increment miss
		if(b_cGuess != true)
		{
			i_miss++;
			cout << "You have guess incorrectly you have " << ci_max_miss - i_miss << " misses left" << endl;
		}
		else
		{
			//user got word correct reset the bool
			b_cGuess = false;
		}


	}while (i_miss < ci_max_miss && i_correctGuess != i_word_size);


	//check for win/lose
	if(i_miss == ci_max_miss)
	{
		//lose
		cout << "To bad you lost please try again!";
	}
	else
	{
		//win
		cout << " congrats you Won!!!!";
	}
	return 0;
}