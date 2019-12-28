#include <iostream>;
#include <string>;

using namespace std;

int main(void) {

	string input = "";
	int key = 5;
	int choiceED;
	char choiceEnd = 'E';
	int num = 0;
	do {
		do {
			cout << "Welcome to ENGR1200U Cryptographic Techniques Program" << endl;
			cout << "\t" << "1. Encrypt" << endl;
			cout << "\t" << "2. Decrypt" << endl;
			cout << "Please enter your selection:";
			cin >> choiceED;
		} while (choiceED != 1 && choiceED != 2);

		switch (choiceED) {
		case 1:
			cout << "Please enter message for encryption: ";
			cin.ignore();
			getline(cin, input);

			for (int i = 0; i < input.length(); i++) {

				if (input[i] < 65 || input[i] > 90) {
					continue;
				}
				if (input[i] == 90) {
					input[i] = 65;
				}

				input[i] = (input[i] - 65 + key) % 26 + 65;

			}
			cout << "Encrypted Message: " << input << endl;
			break;
		
		case 2:
			cout << "Please enter message for decryption: ";
			cin.ignore();
			getline(cin, input);

			for (int i = 0; i < input.length(); i++) {

				if (input[i] < 65 || input[i] > 90) {
					continue;
				}
				if (input[i] - key < 65) {

					num = abs(input[i] - 65 - key);
					input[i] = (90 - num + 1);
				} else {
					input[i] = (input[i] - 65 - key) % 26 + 65;
				}
			}
			cout << "Decrypted Message: " << input << endl;
			break;

		default: cout << "INVALID INPUT" << endl; break;
		}
		cout << "Do you want to continue(C - continue, E - End): ";
		cin >> choiceEnd;
	} while (choiceEnd == 'C');
	
	system("pause");
	return 0;
}