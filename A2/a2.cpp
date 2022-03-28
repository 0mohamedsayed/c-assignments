/*
 * a2.cpp
 *
 *      Author: mohamed sayed mohamed mohamed
 * 
 */


// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <cctype>
#include <string.h>
#include "inord_list.h"
using namespace std;

list x;
int wordcount=0;
int charcount=-1;
void read_mains(int argc,char**argv)
{
	string line;
	char main[20]={};
	ifstream myfile (argv[1]);
	int i,j,k;
	if (myfile.is_open())
	{
		while(!myfile.eof())
		{

			i=0;j=0;k++;
			getline (myfile,line);
			while((line[i]!='\0'))
			{

				charcount++;
				if(line[i]!=' ')
				{
					if(( ( line[i]>=48)&&(line[i]<=57) )||((line[i]>=65)&&(line[i]<=90)) || ((line[i]>=97)&&(line[i]<=122)) )
					{
						if(((line[i]>=65)&&(line[i]<=90)))
						{
							main[j]=tolower(line[i]);
						}
						else
						{
							main[j]=line[i];
						}
						j++;
					}

					i++;
					if((line[i]==' ')||(line[i]=='\0'))
					{
						x.insertNode(main,k);
						wordcount++;
					}

				}
				else
				{

					i++;
					j=0;
					for(int l=0;l<20;l++)
					{
						main[l]=0;
					}
				}


			}

			charcount++;

			for(int l=0;l<20;l++)
			{
				main[l]=0;
			}

		}
		myfile.close();

	}
	else
	{
		printf("File not found \n");
	}

}

void read_command(int argc,char**argv)
{
	string line,command;
	string* frequant_words;
	char main[20];
	char argument[20];
	ifstream myfile1 (argv[2]);
	int i,j,k,l,counter;
	if (myfile1.is_open())
	{
		while(!myfile1.eof())
		{
			for(l=0;l<20;l++)
			{
				main[l]=0;
				argument[l]=0;
			}

			i=0;j=0;k=0;
			getline (myfile1,line);

			while((line[i]!=' ')&&(line[i]!='\0'))
			{
				main[j]=line[i];
				i++;
				j++;
			}
			if(j!=0)
			{
				j=0;
				command=main;
				if(line[i]==' ')
				{
					k=1;
					i++;
					while(line[i]!='\0'&&line[i]!=' ')
					{
						argument[j]=line[i];
						i++;
						j++;
					}
					if(line[i]==' ')
					{
						k=0;
					}
				}

				if(command=="wordCount")
				{
					if(k==0)
					{
						cout<<wordcount<<" words"<<endl;
					}
					else
					{
						printf("Incorrect number of arguments \n");
					}
				}
				else if(command=="distWords")
				{
					if(k==0)
					{
						cout<<x.distWords()<<" distinct words"<<endl;
					}
					else
					{
						printf("Incorrect number of arguments \n");
					}
				}
				else if(command=="charCount")
				{
					if(k==0)
					{
						cout<<charcount<<" characters"<<endl;				}
					else
					{
						printf("Incorrect number of arguments \n");
					}
				}
				else if(command=="frequentWord")
				{
					if(k==0)
					{
						frequant_words=x.frequentWord();

						counter=0;

						cout<<"Most frequent word is: ";

						for(counter=0;counter<=392;counter++)
						{
							if(frequant_words[counter]!="")
								cout<<frequant_words[counter]<<" ";
						}
						cout<<endl;

					}
					else
					{
						printf("Incorrect number of arguments \n");
					}
				}
				else if(command=="countWord")
				{

					if(k==1)
					{
						cout<<argument<<" is repeated "<<x.countWord(argument)<<" times"<<endl;
					}
					else
					{
						printf("Incorrect number of arguments \n");
					}
				}
				else if(command=="starting")
				{
					if(k==1)
					{
						x.starting(argument);
					}
					else
					{
						printf("Incorrect number of arguments \n");
					}
				}
				else if(command=="containing")
				{

					if(k==1)
					{
						x.containing(argument);
					}
					else
					{
						printf("Incorrect number of arguments \n");
					}
				}
				else if(command=="search")
				{

					if(k==1)
					{
						x.search(argument);
					}
					else
					{
						printf("Incorrect number of arguments \n");
					}

				}
				else
				{
					printf("Undefined command \n");
				}
			}
			else
				break;
		}
		myfile1.close();
	}
	else
	{
		printf("File not found \n");
	}
}


int main (int argc,char**argv) {
	if(argc==3)
	{
		read_mains(argc,argv);
		read_command(argc,argv);
	}
	else
	{
		printf("Incorrect number of arguments \n");
	}




	return 0;
}

