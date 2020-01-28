#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool is_anagram(string word1_in, string word2_in);
void sort(string & unsortedWord, int i);
void swap(string & word, int a);

int main() {

	ifstream infile("input.txt");

	string word1, word2;
	cout << "enter first test string: ";
	infile >> word1;
	cout << "enter second test string: ";
	infile >> word2;
	if(is_anagram(word1, word2)){
		cout << word1 << " and " << word2
		<< " are anagrams!\n";
	}
	else {
		cout << word1 << " and " << word2
		<< " are not anagrams :(\n";
	}
	return 0;
}

bool is_anagram(string word1_in, string word2_in)
{
	if (word1_in.length() != word2_in.length())
		return false;

	sort (word1_in, (int)word1_in.length());
	sort (word2_in, (int)word2_in.length());

	for (unsigned int index = 0; index < word1_in.length(); index++)
	{
		if (word1_in.substr(index, 1) != word2_in.substr(index,1))
			return false;
	}
	return true;
}

void sort(string & unsortedWord, int i)
{
	if (i == 0)
		return;
	for (int x = 1; x < i-1; x++)
	{
		if (unsortedWord.substr(x,1) > unsortedWord.substr(x+1,1))
			swap(unsortedWord,x);
	}
	sort(unsortedWord,i-1);

}

void swap(string & word, int a)
{
	string temp;
	temp = word.substr(a,1);
	word.replace(a, 1, word.substr(a+1,1));
	word.replace(a+1, 1, temp);

}
