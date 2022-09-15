#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool liczba(const char& n) {
	return (n >= '0' && n <= '9') ? true : false;
}
bool znak(const char& n){
	switch (n) {
		case '+': case '-': case '/': case '*':{
				return true;
		}break;
		default: return false;
	}
}
int string_to_int(const string& n,int& poz) {
	int licz = 0;
	while(poz < n.size() && liczba(n[poz])){
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
	stack<int> stos;
	string onp;
	int a, b;
	//getline(cin, onp);
	for (int i = 0; i < onp.size(); i++) {
		if (liczba(onp[i])) {
			stos.push(string_to_int(onp, i));
		}else if(znak(onp[i])){
			if (stos.size() < 2) {
				cout << "Nie prawidlowe dane" << endl;
				return 0;
			}
			a = stos.top();
			stos.pop();
			b = stos.top();
			stos.pop();
			stos.push(dzialanie(b, a, onp[i]));
		}
	}
	if (stos.size() != 1) {
		cout << "Nie prawidlowe dzialanie ONP" << endl;
		return 0; 
	}
	cout << "Wynik dzialania: " << onp << " wynik: " << stos.top() << endl;
	return 0;
}