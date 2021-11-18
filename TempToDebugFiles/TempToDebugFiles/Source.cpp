#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	int t;
	string n;
	long long int num = 1;
	long long int counter = 0;
	bool llego = true;
	stringstream s;
	for (cin >> t; t > 0; t--) {
		cin >> n;
		cout << n.length();
		if (n.length() == 1) {
			llego = false;
		}
		while (llego) {
			counter++;
			for (int i = 0; i < n.length(); i++) {
				num *= n.at(i) - '0';
			}
			s << num;
			if (s.str().length() == 1) {
				llego = false;
			}
			else {
				n = s.str();
			}
		}
		cout << counter << endl;
	}
	return 0;
}