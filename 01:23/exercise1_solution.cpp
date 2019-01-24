#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

vector<vector<string> > readAndParse(string filename);
void coutWords(vector<vector<string> >& words);

vector<vector<string> > readAndParse(string filename) {
	ifstream iss(filename);
	string line;
	vector<vector<string> > words;
	while (getline(iss, line)) {
		stringstream ss(line);
		vector<string> lineOfWords;
		string word;
		while (ss >> word) {
			lineOfWords.push_back(word);
		}
		if (!lineOfWords.empty())
			words.push_back(lineOfWords);
	}
	return words;
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