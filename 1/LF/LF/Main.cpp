#include <iostream>
#include <string>

using namespace std;

int main()
{
	//constants
	const int ci_GP = 900;

	//variables
	string s_leader;
	int i_party;
	int i_dead;

	//Gather info
	//main output

	cout << "Welcome to the game!!" << endl;
	cout << "Please input your first name: ";
	cin >> s_leader;


	cout << "Please input a positive number: ";
	cin >> i_party;

	cout << "Please enter a positive number that is less than previous number: ";
	cin >> i_dead;


	//output story time
	cout << "Here is your story: " << endl << endl;

	cout << s_leader << " is the brave leader on a quest.";
	cout << "Through travelin over the land " << s_leader 
		<< " made a party with " << i_party << " people." << endl;
	cout << "As they were traveling a rogue demons appears and only " 
		<< i_party - i_dead << " of the members remain." << endl;
	cout << "The demon dropped " << ci_GP << " gold. The gold was split and "
		<< s_leader << " kept the extra " << (ci_GP % (i_party - i_dead)) << " gold." <<endl;
	cout <<  "The End" ;

	//dummy input to view results 
	cin >> i_dead;

	return 0;
}