#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

vector <int> toASCIIcode(string &s) {
	vector <int> ASCIInumber;
	for (auto i : s) {
		ASCIInumber.push_back(int(i));
	}
	return ASCIInumber;
}

string toASCIIchar(vector <int> &EncriptedV) {
	vector <char> ASCIIchar;
	for (int i = 0; i < EncriptedV.size(); ++i) {
		if (EncriptedV[i] < 32) {
			cout << "dude, what is this" << endl;
			continue;
		}
		ASCIIchar.push_back(char(EncriptedV[i]));
	}
	string str(ASCIIchar.begin(), ASCIIchar.end());
	return str;
}

bool checkPassword(string password, unsigned long RealCode) {
	if (stoul(password) == RealCode) {
		return true;
	}
	return false;
}

unsigned long hashDjb2(vector <int> &secret) {
	
	unsigned long hash = 5381;
	int c;
	for (auto i : secret) {
		hash = ((hash << 5) + hash ) + i;
	}
	return hash;
}


int main() {
	std::string email;

	std::cout << "Enter e-mail:" << endl;
	getline(cin, email);

	vector <int> SecretCode;
	for (auto i : email) {
		SecretCode.push_back(int(i));
	}

	unsigned long RealSecretCode = hashDjb2(SecretCode);
	string password;
	cout << "psst, here is your code: " << RealSecretCode << endl;
	cout << "Enter your secret code:" << endl;
	do {
		getline(cin, password);
		if (password.empty()) {
			cout << "I said to enter your code, duh" << endl;
		}
	} while (password.empty());

	try {
		if (checkPassword(password, RealSecretCode)){
			cout << "nice" << endl;
			cin.get();
		}
		else {
			cout << "WA. Too bad, try again" << endl;
			cin.get();
		}
	}

	catch (...) {		
		cout << "ABORT" << endl;
		cin.get();
		return 1; 
	}
	return 0;
}