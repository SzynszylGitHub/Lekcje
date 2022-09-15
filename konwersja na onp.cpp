#include <iostream>
#include <string>
#include <stack>

using namespace std;
// konwersja na ONP
const int maksymalny_priorytet = 2;
int priorytet(char oper) {
	switch (oper) {
	case'/':case'*': {return 2; }break;
	case'+':case'-': {return 1; }break;
	case'(':case')': {return 0; }break;
	default: {
		cout << "Nieprawidlowy priorytet" << endl;
		return 0; 
	}break;
	}
}
bool czy_liczba(char liczba){
	return liczba >= '0' && liczba <= '9';
}
bool czy_operator(char oper) {
	switch (oper) {
	case'+':case'-':case'/':case'*':{
		return true;
	} break;
	default: {
		return false;
	}break;
	}
}
bool czy_NZ(char oper) {
	return oper == ')';
}
bool czy_NO(char oper) {
	return oper == '(';
}
string string_to_string(const string& NP, int& poz) {  
	string liczba = "";
	while (czy_liczba(NP[poz]) && poz < NP.size() ) {
		liczba += NP[poz];
		poz++;
	}
	poz--;
	return liczba;
}
// obliczanie ONP
int string_to_int(const string& n, int& poz) {
	int licz = 0;
	while (poz < n.size() && czy_liczba(n[poz])) {
		// schemat hornera
		licz = licz * 10 + n[poz] - '0';
		poz++;
	}
	poz--;
	return licz;
}
int dzialanie(int a, int b, char oper) {
	switch (oper) {
	case '+': {return a + b; }break;
	case '-': {return a - b; }break;
	case '*': {return a * b; }break;
	case '/': {return a / b; }break;
	}
	cout << "Nie prawidlowy operator: " << oper << endl;
	return 0;
}



int main() {
	// konwersja zwyklego zapisy na ONP
	stack<char> stos;
	string NP, ONP = "";
	getline(cin, NP);
	for (int i = 0; i < NP.size(); i++) {
		if (czy_liczba(NP[i])) { ONP += string_to_string(NP,i); ONP += ' '; }
		else 
			if (czy_operator(NP[i])) {
				if (stos.size() == 0) {
					stos.push(NP[i]);
				}
				else {
					if (priorytet(stos.top()) < priorytet(NP[i])) {
						stos.push(NP[i]);
					}
					else if (priorytet(stos.top()) == maksymalny_priorytet || priorytet(stos.top()) == priorytet(NP[i])) {
						while (!stos.empty()) {
							if (!(priorytet(stos.top()) >= priorytet(NP[i]))) break;
							if (priorytet(stos.top()) != 0) { ONP += stos.top(); ONP += ' '; }
							stos.pop();
						}
						stos.push(NP[i]);
					}
				}

			}	
			else
				if (czy_NO(NP[i])) {
					stos.push(NP[i]);
				}
				else 
					if (czy_NZ(NP[i])) {
						while (!czy_NO(stos.top()) && stos.size() > 0) {
							if (priorytet(stos.top()) != 0) { ONP += stos.top(); ONP += ' '; }
						
							stos.pop();
						}
						stos.pop();
					}
		
	}
	if (stos.size() > 0) {
		for (unsigned int  i = 0; i < stos.size(); i++) {
			if (priorytet(stos.top()) != 0) { ONP += stos.top(); ONP += ' '; }
			stos.pop();
		}
	}
	cout << "Podane wyrazenie w notacji NP: " << NP << endl;
	cout << "Wyrazenie przeksztalcone na ONP: " << ONP << endl;
	
	// obliczanie ONP
	stack<int> stos_2;
	string onp = ONP; // zamiast getline()
	int a, b;
	//getline(cin, onp);
	for (int i = 0; i < onp.size(); i++) {
		if (czy_liczba(onp[i])) {
			stos_2.push(string_to_int(onp, i));
		}
		else if (czy_operator(onp[i])) {
			if (stos_2.size() < 2) {
				cout << "Nie prawidlowe dane" << endl;
				return 0;
			}
			a = stos_2.top();
			stos_2.pop();
			b = stos_2.top();
			stos_2.pop();
			stos_2.push(dzialanie(b, a, onp[i]));
		}
	}
	if (stos_2.size() != 1) {
		cout << "Nie prawidlowe dzialanie ONP" << endl;
		return 0;
	}
	cout << "Wynik dzialania: " << onp << " wynik: " << stos_2.top() << endl;

	system("pause");
	
	return 0;
}