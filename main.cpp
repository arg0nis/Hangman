#include <iostream>
#include <string>

#define ARR_SIZE_DRUHSLOVA 23

using namespace std;

string guessedIndicator;
string zlePismena;

const string druhSlova[ARR_SIZE_DRUHSLOVA] = {
	"zviera", "v dome", "oblecenie", "jedlo", "osobne", "povolanie", "v kupelni", "telo", "pocitac", "sport", "v kuchyni", "priroda", "hudba", "predmet", "dopravny prostriedok", "v nemocnici", "stavba", "miesto", "predmet v skole", "krajina", "v zahrade", "vlastnost", "farba"
};


void enterWord() {

}

void drawHang(int stage, string druhslovicka) {
	for (int i = 0; i < 50; i++) {
			cout << endl;
	}
	cout << "    " << druhslovicka;


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
	cout << "Nespravne pismena: " << zlePismena << endl;
}

void drawWord(string word) {
	//guessedIndicator = word;

	cout << "   ";

	for (int i = 0; i < word.length(); i++) {
		cout << guessedIndicator[i] << " ";
	}
	cout << endl;
}

int guessLetter(string word) {
	int guessed = 0;
	char letter;
	int wordLength = word.length();
	string line = "_ ";

	cout << endl;
	cout << "Hadaj pismeno: ";
	cin >> letter;

	for (int i = 0; i < wordLength; i++) {
		if (word[i] == letter) {
			guessedIndicator[i] = word[i];
			guessed = 1;
		} 
	}
	if (not guessed) {
		zlePismena = zlePismena + letter + ", ";
	}
	cout << endl;

	return guessed;
}

int main() { 
	int stage = 0;
	int running = 1;
	int typslova;

	string word;
	string druhslovicka;
	
	for (int i = 0; i < 50; i++) {
		cout << endl;
	}
	cout << "Zadaj Slovo: ";
	cin >> word;
	for (int i = 0; i < ARR_SIZE_DRUHSLOVA; i++) {
		cout << i << ")" << druhSlova[i] << endl;
	}
	cout << 23 << ")" << "Ine" << endl;
	cout << endl << "Vyber typ slova: ";
	cin >> typslova;

	if (typslova < 23) {
		for (int i = 0; i < 50; i++) {
			cout << endl;
		}
		druhslovicka = druhSlova[typslova];
	} else if (typslova = 23) {
		string inytyp;
		cout << "Zadajte Druh Slova: ";
		cin >> inytyp; 

		for (int i = 0; i < 50; i++) {
			cout << endl;
		}
		druhslovicka = inytyp;
	}

	char nothing = ' ';

	for (int i = 0; i < word.length(); i++) {
		guessedIndicator = guessedIndicator + nothing;
	}
	

	while (running == 1) {
		
		drawHang(stage, druhslovicka);
		drawWord(word);
		drawField(word);

		if (guessedIndicator == word) {
			cout << "Gratulujem!! Vyhral si!" << endl;
			running = 0;
			break;
		}

		if (not guessLetter(word)) {
			if (stage < 4) {
				stage++;	
			}	else {
				cout << endl << "Prehral si :(" << endl;
				cout << "Slovo bolo: " << word << endl;
				running = 0;
				break;
			}
		} 
		

	}


	return 0;
}






