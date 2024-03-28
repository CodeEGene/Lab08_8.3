#include <iostream>
#include <string>
using namespace std;

int convertRomanToInt(string s);

int main() {

	string input;
	while (true) {
		cout << "Enter Roman number or Q to quit: ";
		getline(cin, input);
		if (input == "Q" || input == "q") break;
		cout << input << " = " << convertRomanToInt(input) << endl;
	}

	return 0;
}

int convertRomanToInt(string s) {
	const int ROMAN_LENGTH = s.length();
	int* lettersInRoman = new int[ROMAN_LENGTH + 1];

	for (int i = 0; i < ROMAN_LENGTH; i++) {
		switch (s[i]) {
		case 'I':
			lettersInRoman[i] = 1;
			break;
		case 'V':
			lettersInRoman[i] = 5;
			break;
		case 'X':
			lettersInRoman[i] = 10;
			break;
		case 'L':
			lettersInRoman[i] = 50;
			break;
		case 'C':
			lettersInRoman[i] = 100;
			break;
		case 'D':
			lettersInRoman[i] = 500;
			break;
		case 'M':
			lettersInRoman[i] = 1000;
			break;
		default:
			cerr<<"There was a typo or something.";
			exit(1);
			break;
		}
	}

	lettersInRoman[ROMAN_LENGTH] = 0;

	int total = 0;
	int previousValue = 0;

	if (ROMAN_LENGTH == 1) {
		return lettersInRoman[0];
	}

	for (int i = 0; i < ROMAN_LENGTH; i++) {
		if (lettersInRoman[i] >= lettersInRoman[i + 1]) {
			total += lettersInRoman[i];
		}
		else {
			total += lettersInRoman[i + 1] - lettersInRoman[i];
			lettersInRoman[i + 1] = 0;
		}
	}
	delete[] lettersInRoman;

	return total;

}