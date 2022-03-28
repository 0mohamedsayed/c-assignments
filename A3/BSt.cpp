/*
 * BSt.cpp
 *
 * 
 *      Author: mohamed sayed mohamed
 */


#include <iostream>

#include "BST.h"

using namespace std;

tree*btr;
tree*str;

tree::tree()
{
	left=NULL;
	right=NULL;
	final_ptr=NULL;
	delet=NULL;
	final_ptr=NULL;
	check=NULL;
	emptyptr=true;
	hour=0;
	day=1;
	counter=0;
	count=0;
	coun=0;
	first=0;
}

bool tree::is_empty(void)
{
	return emptyptr;
}

tree* tree :: goleft (tree* y)
{

	if (!y->is_empty())
	{
		str=y;
		goleft(y->left);
	}
	return y;
}



void tree::add_root(char* TITLE,int DAY,int HOUR,tree* z)
{
	count=1;
	check=find(DAY,HOUR,z);
	if (emptyptr) {
		if(coun==0)
		{
			emptyptr= false;
			left = new tree;
			right = new tree;
			title = TITLE;
			day=DAY;
			hour=HOUR;
			first=1;
		}
		else
		{
			cout<<"Conflict "<<DAY<<" "<<HOUR<<endl;
			coun=0;
		}

	}

	else if (DAY == day)
	{
		if(HOUR<hour)
			left->add_root(TITLE,DAY,HOUR,z); // insert in left subtree
		else
			right->add_root(TITLE,DAY,HOUR,z); // insert in right subtree
	}
	else if (DAY < day)
		left->add_root(TITLE,DAY,HOUR,z); // insert in left subtree
	else
		right->add_root(TITLE,DAY,HOUR,z); // insert in right subtree
	count=0;

}





void tree::print(tree* bt)
{
	if(first==1)
	{
		if (!bt->is_empty()) {
			// traverse left child
			print(bt->left);
			// visit tree
			cout <<bt->title<<" "<<bt->day<<" "<<bt->hour<<endl;
			// traverse right child
			print(bt->right);
		}
	}
	else
		cout<<"Empty Planner"<<endl;
}


tree* tree :: find ( int day,int hour,tree* y)
{
	if(!y->is_empty())
	{
		if(day == y -> day)
		{
			if(hour == y -> hour)
			{
				coun=1;
				if(counter==0&&count==0)
					cout<< y-> title<<endl;
				else
				{
					counter=0;
					btr=y;
				}
				return y;
			}
			else if(hour < y -> hour)
			{
				y = y -> left;
				find(day,hour,y);
			}
			else if(hour > y -> hour)
			{
				y = y-> right;
				find(day,hour,y);
			}
		}
		else if(day < y -> day)
		{
			y = y -> left;
			find(day,hour,y);
		}
		else if (day > y -> day)
		{
			y =y-> right;
			find(day,hour,y);
		}
	}
	else
	{
		if(count==0)
		{
			cout<<"Empty"<<" "<<day<<" "<<hour<<endl;
			counter=1;
		}
	}
	return y;
}


int tree :: modify (int day , int hour , tree* y, char* title)
{
	if(!y->is_empty())
	{
		if(day == y -> day)
		{
			if(hour == y -> hour)
			{
				y-> title=title;
				return 0;
			}
			else if(hour < y -> hour)
			{
				y = y -> left;
				modify(day,hour,y,title);
			}
			else if(hour > y -> hour)
			{
				y = y-> right;
				modify(day,hour,y,title);
			}
		}
		else if(day < y -> day)
		{
			y = y -> left;
			modify(day,hour,y,title);
		}
		else if (day > y -> day)
		{
			y =y-> right;
			modify(day,hour,y,title);
		}
	}
	else
	{
		cout<<"Empty"<<" "<<day<<" "<<hour<<endl;
	}
	return 0;
}

void tree::del( int day,int hour,tree* y)
{
	counter=1;

	find(day,hour,y);
	y->delet=btr;

	if(counter==0)
	{
		if(!delet->is_empty())
		{
			if ((delet->left->title=="")&&(delet->right->title==""))
			{
				y->delet->title="";
				y->delet->day=1;
				y->delet->hour=0;
				y->delet->emptyptr=true;
			}
			else if((delet->left->title==""))
			{
				delet->title=delet->right->title;
				delet->day=delet->right->day;
				delet->hour=delet->right->hour;
				delet->emptyptr=delet->right->emptyptr;
				delet->right=new tree;
			}
			else if((delet->right->title==""))
			{

				delet->title=delet->left->title;
				delet->day=delet->left->day;
				delet->hour=delet->left->hour;
				delet->emptyptr=delet->left->emptyptr;
				delet->left=new tree;
			}
			else
			{
				goleft(delet->right);
				delet->title=str->title;
				delet->day=str->day;
				delet->hour=str->hour;

				y->delet=str;
				y->delet->title="";
				y->delet->day=1;
				y->delet->hour=0;
				y->delet->emptyptr=true;
			}



		}
	}
	counter=0;


}
