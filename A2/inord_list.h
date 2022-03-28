/*
 * inord_list.h
 *
 *      Author: mohamed sayed mohamed mohamed
 *      
 */

#ifndef INORD_LIST_H_
#define INORD_LIST_H_

#include <string>
using namespace std;

class list{
public:
	list();
	~list();
	void insertNode(char* woord,int index);
	int distWords();
	string* frequentWord();
	int countWord(char* word);
	void starting(char* word);
	void containing(char* word);
	void search(char* word);
	void print();
private:
	struct Node;
	typedef Node* link;

	struct Node
	{
	int index;
	string WORD;
	link next;
	};
link head;
link tail;
link current;
link addednode;
link pre;
link ptr;
int count=0;
int counter=0;
int numberofrepeat=0;
int mostfrequant=0;
string frequant_word[400];
string most_frequant_words[400];
int frequant[400];
string Word;
int c=0;
};



#endif /* INORD_LIST_H_ */
