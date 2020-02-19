#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	string templ;
	string s;
	cin >> templ; //шаблон
	cin >> s; //строка
	int len_templ = templ.length();
	int len_s = s.length();
	//Считаю Z функцию для шаблона
	int l = 0;
	int r = 0;
	vector<int> zfuncshabl(len_templ, 0);
	for (int i = 1; i < len_templ; i++) {
		zfuncshabl[i] = max(0, min(zfuncshabl[i - l], r - i + 1));
		while ((i + zfuncshabl[i] <= len_templ) && (templ[zfuncshabl[i]] == templ[i + zfuncshabl[i]])) {
			zfuncshabl[i]++;
		}
		if (i + zfuncshabl[i] - 1 > r) {
			l = i;
			r = i + zfuncshabl[i] - 1;
		}
	}

	//Ищу совпадение строки с шаблоном используя посчитанную Z функцию шаблона 
	r = 0;
	l = 0;
	int z = 0;
	for (int i = 0; i < len_s; i++) {
		z = max(0, min(zfuncshabl[i - l], r - i + 1));


		while ((i + z < len_s) && (templ[z] == s[i + z]))
		{
			z++;
		}

		if (i + z - 1 > r) {
			r = i + z - 1;
			l = i;
		}
		if (z == len_templ) {
			cout << i << " ";

		}

	}
}