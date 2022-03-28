/*
 * inord_list.cpp
 *
  *      Author: mohamed sayed mohamed mohamed
 *      
 */
#include "inord_list.h"
#include <iostream>
#include <string>
using namespace std;

list::list()
{
	head=NULL;
	tail=NULL;
	current=NULL;
	addednode=NULL;
	pre=NULL;
	ptr=NULL;
}



list::~list()
{

	current=head;

	while(current!=NULL)
	{
		delete current;
		current=current->next;
	}

}


void list::insertNode(char* woord, int index)
{

	addednode=new Node;
	addednode->WORD=woord;
	addednode->index=index;


	if(head==NULL||woord<=head->WORD)
	{
		if(head==NULL)
		{
			addednode->next=head;
			head=addednode;
			tail=head;
		}
		else
		{
			addednode->next=head;
			head=addednode;
		}
	}
	else if(woord>=tail->WORD)
	{
		tail->next=addednode;
		addednode->next=NULL;
		tail=addednode;
	}
	else
	{
		pre=head;
		while(pre->next->WORD < woord)
		{
			pre=pre->next;
		}
		addednode->next=pre->next;
		pre->next=addednode;

	}

}




void list::print(void)
{
	current=head;

	while(current!=NULL)
	{
		cout<<current->WORD<<" ";
		current=current->next;
	}

}





int list::distWords()

{
	current=head;
	count=0;

	while(current->next!=NULL)
	{
		if(current->WORD!=current->next->WORD)
		{
			count++;
		}
		current=current->next;
	}
	return count+1;

}

string* list::frequentWord()
{
	ptr=head;
	while(ptr->WORD=="")
	{
		ptr=ptr->next;
	}


	current=ptr;
	count=0;
	while(current->next!=NULL)
	{
		numberofrepeat=1;
		if(current->WORD!="the"&&current->WORD!="is"&&current->WORD!="a"&&current->WORD!="an"&&current->WORD!="for"&&current->WORD!="in"&&current->WORD!="on"&&current->WORD!="at"&&current->WORD!="or"&&current->WORD!="and"&&current->WORD!="are"&&current->WORD!="was")
		{
			if(current->WORD==current->next->WORD)
			{
				frequant_word[count]=current->WORD;
				current=current->next;

				while((current->WORD==frequant_word[count])&&(current->next!=NULL))
				{
					numberofrepeat++;
					current=current->next;
				}

				if(current->WORD==frequant_word[count])
				{
					numberofrepeat++;
					frequant[count]=numberofrepeat;
				}
				else
				{
					frequant[count]=numberofrepeat;
				}

				count++;
			}
			else
			{
				current=current->next;
			}
		}
		else
			current=current->next;
	}

	mostfrequant=frequant[0];

	for(count=1;count<=392;count++)
	{
		if(frequant[count]>mostfrequant)
		{
			mostfrequant=frequant[count];
		}
	}
	counter=0;
	for(count=0;count<=400;count++)
	{
		if(frequant[count]==mostfrequant)
		{
			most_frequant_words[counter]=frequant_word[count];
			counter++;
		}
	}

	return most_frequant_words;
}


int list::countWord(char* word)
{

	current=head;
	counter=0;

	while(current!=NULL)
	{

		if(word==current->WORD)
		{
			counter++;
		}
		current=current->next;
	}

	return counter;

}


void list::starting(char* word)
{

	current=head;
	counter=0;
	count=0;
	numberofrepeat=0;
	while(current!=NULL)
	{
		while(word[counter]!=0)
		{
			if(word[counter]==current->WORD[counter])
			{
				count++;
			}
			counter++;
		}
		ptr=current;
		Word=current->WORD;
		if(count==counter)
		{
			numberofrepeat=1;
			current=head;
			counter=0;

			while(current!=NULL)
			{

				if(Word==current->WORD)
				{
					counter++;
				}
				current=current->next;
			}
			cout<<Word<<":"<<" "<<counter<<"\t";

		}
		current=ptr;
		current=current->next;
		while((current!=NULL)&&(Word==current->WORD))
		{
			current=current->next;
		}
		count=counter=0;
	}
	if(numberofrepeat==0)
	{
		printf("Word not found \n");
	}
	else
		cout<<endl;



}


void list::containing(char* word)
{
	current=head;
	counter=0;
	count=0;
	mostfrequant=2;
	while(current!=NULL)
	{
		numberofrepeat=0;
		while(current->WORD[counter]!='\0')
		{
			count=0;
			while((word[count]!=current->WORD[counter])&&(current->WORD[counter]!='\0'))
			{
				counter++;
			}
			if(current->WORD[counter]=='\0')
			{
				break;
			}
			else
			{
				counter++;
				count++;

				while((word[count]==current->WORD[counter])&&word[count]!=0)
				{
					count++;
					counter++;
					numberofrepeat=1;
				}
				if(word[count]!=0)
				{
					numberofrepeat=0;
				}
				else
				{
					numberofrepeat=1;
					break;
				}


			}
		}
		ptr=current;
		Word=current->WORD;
		if(numberofrepeat!=0)
		{
			current=head;
			counter=0;

			while(current!=NULL)
			{

				if(Word==current->WORD)
				{
					counter++;
				}
				current=current->next;
			}
			cout<<Word<<":"<<" "<<counter<<"\t";
			mostfrequant=1;
		}
		current=ptr;
		current=current->next;
		while((current!=NULL)&&(Word==current->WORD))
		{
			current=current->next;
		}
		count=counter=0;
	}
	if(mostfrequant==2)
	{
		printf("Word not found \n");
	}
	else
		cout<<endl;


}



void list::search(char* word)
{

	current=head;
	counter=0;
	count=0;
	c=2;
	while(current!=NULL)
	{
		for(int l=0;l<399;l++)
		{
			frequant[l]=0;
		}
		mostfrequant=0;
		numberofrepeat=0;
		while(current->WORD[counter]!='\0')
		{
			count=0;
			while((word[count]!=current->WORD[counter])&&(current->WORD[counter]!='\0'))
			{
				counter++;
			}
			if(current->WORD[counter]=='\0')
			{
				break;
			}
			else
			{
				counter++;
				count++;

				while((word[count]==current->WORD[counter])&&word[count]!=0)
				{
					count++;
					counter++;
					numberofrepeat=1;
				}
				if(word[count]!=0)
				{
					numberofrepeat=0;
				}
				else
				{
					numberofrepeat=1;
					break;
				}


			}
		}
		Word=current->WORD;
		if(numberofrepeat!=0)
		{
			numberofrepeat=1;
			cout<<Word<<":"<<"\t"<<"lines"<<" ";
			while((current!=NULL)&&(Word==current->WORD))
			{
				frequant[mostfrequant]=current->index;
				current=current->next;
				mostfrequant++;
			}
			while(mostfrequant!=0)
			{
				mostfrequant--;
				cout<<frequant[mostfrequant]<<" ";

			}
			cout<<endl;
			c=1;
		}
		else
		{
			current=current->next;
		}
		count=counter=0;
	}
	if(c==2)
	{
		printf("Word not found \n");
	}


}







