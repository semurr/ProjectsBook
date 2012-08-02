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
		"Jump",
		"Fire",
		"Tower",
		"apple",
		"telephone",
		"infrastructure"
	};

	//variables
	int i_word_size;
	int i_miss = 0;
	int i_word_position;
	srand((unsigned)time(0));
	
	//TODO
	//need to set a variable that will see what letter swere found.


	//gather variable
	i_word_position = rand() % ci_num_words;
	i_word_size = cs_words[i_word_position].size();

	//todo remove later
	//debug output
	cout << "word using" << cs_words[i_word_position] << " Size " << cs_words[i_word_position].size() << endl;
	
	//main output
	cout << " Welcome to hang man" << endl;
	cout << " You have get a total of " << ci_max_miss << " misses guess wisely!" << endl << endl;

	cout << " The word has " << i_word_size << " letters." << endl << endl;

	do
	{
		cout << "Please enter a letter: ";

		//TODO
		//check if letter is correct then mark variable if true or not

		//TODO
		//increment if false

		//TODO
		//dispaly word figured out so far

	}while (i_miss > ci_max_miss);


	//output to so can read
	cin >> i_word_size;
	return 0;

}