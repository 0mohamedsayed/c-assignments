/*
 * BST.h
 *
 *  Created on: Jun 1, 2021
 *      Author: student
 */
#ifndef BST_H_
#define BST_H_


#include <string>
using namespace std;

class tree{

public:

	tree();

	bool is_empty();

	void add_root(char* TITLE,int DAY,int HOUR,tree*z);
	void print(tree*);
	tree* find (int day,int hour,tree* y);
	void del (int day,int hour,tree* y);
	int modify (int day , int hour , tree* y, char* title);
	tree* goleft(tree*);


private:
	typedef tree* link;
	string title;
	int day;
	int hour;
	int counter;
	int count;
	int coun;
	int first;
	link left;
	link right;
	link delet;
	link final_ptr;
	link check;
	bool emptyptr;

};


#endif /* BST_H_ */
