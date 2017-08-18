#include <iostream>
#include <string>

int main() {

	std::string word;
	char vowelChecker; //used to check each letter of word for vowels
	char option;//used to check if user wants to enter a new word
	int lenghtOfWord; //used to store size of word user inputted
	int totalVowels; //used to store total number of vowels in word

	struct letterCount { //struct to keep tract of vowel count
		int letterA=0;
		int letterE=0;
		int letterI=0;
		int letterO=0;
		int letterU=0;
	};

	letterCount access; //used to access variables in struct

	std::cout << "==========================" << std::endl;
	std::cout << "=       Vowel Counter    =" << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << std::endl;
	std::cout << "Enter Word:";
	std::cin.ignore(); //used to get rid of \n which creates bug if user decides to enter a new word
	getline(std::cin, word); //gets full line that user entered instead of a single word
	std::cout << std::endl;
	lenghtOfWord = word.length(); //sets to size of word

	for (int i = 0; i < lenghtOfWord; i++) {//for loop to check for vowels in word one character at a time
		vowelChecker = word[i]; //set to char at index i

		// if-else if statements to incrment vowel count of each vowel if the character stored in char vowelChecker is a vowel
		if (vowelChecker == 'a' || vowelChecker == 'A') {
			access.letterA++;
		}
		else if (vowelChecker == 'e' || vowelChecker == 'E') {
			access.letterE++;
		}
		else if (vowelChecker == 'i' || vowelChecker == 'I') {
			access.letterI++;
		}
		else if (vowelChecker == 'o' || vowelChecker == 'O') {
			access.letterO++;
		}
		else if (vowelChecker == 'u' || vowelChecker == 'U') {
			access.letterU++;
		}
	}
	totalVowels = access.letterA + access.letterE + access.letterI + access.letterO + access.letterU; // adds total values of all vowels

	//prints out each vowel count
	std::cout << "# of Vowel A: "<<access.letterA<<std::endl;
	std::cout << "# of Vowel E: " << access.letterE << std::endl;
	std::cout << "# of Vowel I: " << access.letterI << std::endl;
	std::cout << "# of Vowel O: " << access.letterO << std::endl;
	std::cout << "# of Vowel U: " << access.letterU << std::endl;
	std::cout << std::endl;
	std::cout << "Total # of Vowels:" << totalVowels << std::endl;

	std::cout << "Enter a new word?(Y/N): "; //ask user if they want to enter a new word
	std::cin >> option;

	if (option == 'y' || option == 'Y') {
		system("CLS"); //clears screen
		main(); //returs main
	}
	else if (option == 'n' || option == 'N') {
		exit(1); //exits application
	}
	else {
		std::cout << std::endl;
		std::cout << "Invalid option chosen, program will now terminate...." << std::endl;
		std::cin.fail(); //checks for failure in input
		std::cin.clear(); //clears input
		std::cin.ignore(1000, '\n'); //ignores up to 1000 invalid characters input by user
		exit(1); //exits application
	}

	return 0;
}