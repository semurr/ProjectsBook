//hex/dec/bin converter
#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>
using namespace std;

//declaring functions
int binToDecConverter(int value);
string binToHexConverter(int value);

int main()
{
	//variable
	int binValue = 1000101010;    
	int decValue = 0;            //hold the binary value in decimal form
	string hexValue = "";


	decValue = binToDecConverter(binValue);
	hexValue = binToHexConverter(binValue);
	
	cout << "decValue = " << decValue << endl;
	cout << "hexValue = "<< hexValue;

	cin >> decValue;

	return 0;
}

//binary to decimal converter
int binToDecConverter(int value)
{
	int binaryReturnValue = 0;
	//find the binary length
	//find out how many time sthe value is divisble by 10 
	int binLength = (int)log10(value + 0.0);

	//run through the loop until binLength get set to 0
	do
	{
		//check to see if the length of the value to the power of 2 is greater then the current value
		//if so add that decimal and subtract by 10
		if(value / (int)pow(10.0, binLength) != 0)
		{
			binaryReturnValue = binaryReturnValue + (int)pow(2.0, binLength);
			value = value - (int)pow(10.0, binLength);
		}

		binLength--;
	}
	while(binLength != 0);

	return binaryReturnValue;
}

string binToHexConverter(int value)
{
	int binCompare[16] = {1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111};
	string hexCompare[16] = {"1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
	string result = "";
	//find the length of the binary value
	int binLength = (int)log10(value + 0.0);

	int fourBitV = 0;

	//check the last 4 digit 
	for(int i = binLength; i > 0; i = i - 4)
	{
		if(value >= 1000)
		{
			fourBitV = value % 10000;
		}
		else
		{
			fourBitV = value;
		}

		for(int y = 0; y != 16; y++)
		{
			if( fourBitV == binCompare[y])
			{
				string nResult = hexCompare[y];
				result = nResult.append(result);
				value = value / 10000;
				break;
			}

			if (y == 16)
			{
				result.append("0");
			}
		}
	}

	return result;
}