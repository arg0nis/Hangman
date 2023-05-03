#include <iostream>
#include <string>

#define ARR_SIZE_DRUHSLOVA 23
#define NOTHING ' '

using namespace std;

string guessedIndicator;
string wrongGuesses;

const string wordTypes[ARR_SIZE_DRUHSLOVA] = {
	"Animal", "In House", "Clothing", "Food", "Personal", "Job", "In Bathroom", "Body", "Computer", "Sport", "In Kitchen", "Nature", "Music", "Thing", "Vehicle", "In Hospital", "Building", "Place", "School Subject", "Country", "In Garden", "Color", "Properties"
};

void printEmptyLines(int numberOfLines) {
	for (int i = 0; i < numberOfLines; i++) {
		cout << endl;
	}
}

string enterWord() {
	string word;
	cout << "Enter Word: ";
	cin >> word;
	return word;
}

string getWordType() {
	int wordTypeNumber;
	string wordType;

	for (int i = 0; i < ARR_SIZE_DRUHSLOVA; i++) {
		cout << i << ")" << wordTypes[i] << endl;
	}
	cout << 23 << ")" << "Other" << endl;

	cout << endl << "Enter number of word type: ";
	cin >> wordTypeNumber;

	if (wordTypeNumber < 23) {
		printEmptyLines(50);
		wordType = wordTypes[wordTypeNumber];
	} else if (wordTypeNumber = 23) {
		string otherWordType;
		cout << "Enter word type: ";
		cin >> otherWordType; 

		printEmptyLines(50);
		wordType = otherWordType;
	}
	return wordType;
}

void drawHang(int stage, string wordType) {
	printEmptyLines(50);

	cout << "    " << wordType;

	cout << endl;
	cout << "		/-----" << endl;
	if (stage == 0){
		cout << "		|     " << endl;	
		cout << "		|     " << endl;	
		cout << "		|     " << endl;
		cout << "		|     " << endl;
		cout << "		|     " << endl;
		cout << "		----" << endl;
	} else if (stage == 1){
		cout << "		|    |" << endl;	
		cout << "		|     " << endl;	
		cout << "		|     " << endl;
		cout << "		|     " << endl;
		cout << "		|     " << endl;
		cout << "		----" << endl;
    } else if (stage == 2) {
		cout << "		|    |" << endl;	
		cout << "		|    O" << endl;	
		cout << "		|     " << endl;
		cout << "		|     " << endl;
		cout << "		|     " << endl;
		cout << "		----" << endl;
	} else if (stage == 3) {
		cout << "		|    |" << endl;	
		cout << "		|    O" << endl;
		cout << "		|   /|\\" << endl;
		cout << "		|     " << endl;
		cout << "		|     " << endl;
		cout << "		----" << endl;
	} else if (stage == 4) {
		cout << "		|    |" << endl;	
		cout << "		|    O" << endl;
		cout << "		|   /|\\" << endl;
		cout << "		|   / \\" << endl;
		cout << "		|     " << endl;
		cout << "		----" << endl;
	}
	cout << endl;
}

void drawField(string word) {
	cout << "   ";
	
	for (int i = 0; i < word.length(); i++) {
		cout << "_ ";

	}

	cout << endl;
	cout << "Wrong guesses: " << wrongGuesses << endl;
}

void drawWord(string word) {
	cout << "   ";

	for (int i = 0; i < word.length(); i++) {
		cout << guessedIndicator[i] << " ";
	}

	cout << endl;
}

bool guessLetter(string word) {
	bool guessed = false;
	char letter;
	int wordLength = word.length();
	string line = "_ ";

	cout << endl;
	cout << "Guess Letter: ";
	cin >> letter;

	for (int i = 0; i < wordLength; i++) {
		if (word[i] == letter) {
			guessedIndicator[i] = word[i];
			guessed = true;
		} 
	}
	if (not guessed) {
		wrongGuesses = wrongGuesses + letter + ", ";
	}
	cout << endl;

	return guessed;
}

bool playerWinned(string word) {
	bool winned = false;

	if (guessedIndicator == word) {
		winned = true;
	} 

	return winned;
}

int main() { 
	int stage = 0;
	int running = 1;
	int typslova;

	string word;
	string wordType;
	
	printEmptyLines(50);
	word = enterWord();	

	wordType = getWordType();	

	for (int i = 0; i < word.length(); i++) {
		guessedIndicator = guessedIndicator + NOTHING;
	}
	

	while (running == 1) {
		
		drawHang(stage, wordType);
		drawWord(word);
		drawField(word);

		if (playerWinned(word)) {
			cout << "Congratulations, YOU WON!" << endl << endl;
			running = 0;
			break;
		} 
		if (not guessLetter(word)) { 
			if (stage < 4) {
				stage++;	
			} else {
				cout << endl << "YOU LOSE! :(" << endl;
				cout << "The word was " << word << "." << endl;
				running = 0;
				break;
			}
		}
	}
	return 0;
}






