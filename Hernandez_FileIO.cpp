// Bianca Hernandez
// Created: October 21, 2015
// Summary: 
//
//************************************************************
#include <iostream> // cout/cin
#include <string> // string manipulation
#include <fstream> // files
#include <cstdlib> // exit(1)
#include <iomanip> // precision
#include <cassert> // assert

using namespace std;

//************************************************************
void capitalize(string word);
// Pre-Condition:  word is  not an empty string
// Post Condition: Word is capitalized and added to a the file capitalize.txt
//
//************************************************************

//************************************************************
void uppercase(string word);
// Pre-Condition: word is not an empty string
// Post Condition: The first letter of the word is capitalized and added to the file uppercase.txt
//
//************************************************************

int main()
{
	ifstream fin;
	ofstream fout;
	
	string word;
	int length1 = 0, length2=0, length3=0, length4=0, length5=0, length6=0, length7=0, length8=0, length9=0, length10=0, length11=0;
	double sum = 0;
	int counter = 0;
	
	fin.open("gba.txt");
	fout.open("results.txt");
	
	if(fin.fail()) // checks to make sure something is in the file
	{
		cout << "Error opening input file." << endl;
		exit(1);
	}
	if(fout.fail()) // checks to make sure something is in the file
	{
		cout << "Error opening output file." << endl;
		exit(1);
	}	
	
	while(fin >> word)
	{
		switch(word.length())
		{
			case 1: length1++;
						  break;
			case 2: length2++;
						  break;
			case 3: length3++;
						  break;
			case 4: length4++;
						  break;
			case 5: length5++;
						  break;
			case 6: length6++;
						  break;
			case 7: length7++;
						  break;
			case 8: length8++;
						  break;
			case 9: length9++;
						  break;
			case 10: length10++;
							break;
			default : length11++;			  			  
		}
		capitalize(word);
		uppercase(word);
		sum += word.length();
		counter ++;	
	}
	
	fout << setprecision(2);
	fout << "Average characters per word: " << sum /counter << endl << endl;
	fout << length1 << "  words of length 1" << endl;
	fout << length2 << " words of length 2" << endl;
	fout << length3 << " words of length 3" << endl;
	fout << length4 << " words of length 4" << endl;
	fout << length5 << " words of length 5" << endl;
	fout << length6 << " words of length 6" << endl;
	fout << length7 << " words of length 7" << endl;
	fout << length8 << "  words of length 8" << endl;
	fout << length9 << "  words of length 9" << endl;
	fout << length10 << "  words of length 10" << endl;
	fout << length11 << "  words of length 11 or more." << endl;
	fout << "\nWord Total: " << counter << endl;
	fin.close();
	fout.close();
	
	return 0;
} // End of main()

void capitalize(string word)
{
	assert(word != " "); // assert to make sure the string is not empty
	
	ofstream fout;
	fout.open("capitalize.txt",ios::app); // opens files and adds to it
	
	if(fout.fail()) // checks to make sure something is in the file
	{
		cout << "Error opening output file." << endl;
		exit(1);
	}
	
	for(int i = 0; i < word.length(); i++)
	{
		word[i] = toupper(word[i]);
	}
	
	fout << word << " ";
	
	fout.close(); // closes fout(capitalize.txt) file
} // End of Capitalize()

void uppercase(string word)
{
	assert(word != " "); // assert to make sure the string is not empty
	
	ofstream fout;
	fout.open("uppercase.txt", ios::app); // opens files and adds to it
	
	if(fout.fail()) // checks to make sure something is in the file
	{
		cout << "Error opening output file." << endl;
		exit(1);
	}
	
	word[0] = toupper(word[0]);
	
	fout << word << " ";
	
	fout.close(); // closes fout(uppercase.txt) file
} // End of uppercase()
