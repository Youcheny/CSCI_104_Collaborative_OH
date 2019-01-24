#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

vector<vector<string> > readAndParse(string filename);
void coutWords(vector<vector<string> >& words);

vector<vector<string> > readAndParse(string filename) {
	// TODO
}

void coutWords(vector<vector<string> >& words) {
	for (vector<string>& line : words) {
		for (string& word : line) {
			cout << word << ' ';
		}
		cout << endl;
	} 
}

int main(int argc, char *argv[]) {
	vector<vector<string> > words1 = readAndParse("exercise1_file.txt");
	coutWords(words1);
}