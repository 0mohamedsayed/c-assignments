/*
 * a3.cpp
 *
 * 
 *      Author: mohamed sayed mohamed
 */

#include <string.h>
#include <cmath>
#include "BST.h"
#include <fstream>
using namespace std;

tree x;
tree* bt=&x;
tree* y=&x;
tree* z=&x;


void read_command(int argc,char**argv)
{
	string line,command;
	int day,hour,DAY,HOUR=0;
	char command_char_array[6];
	char argument[20];
	ifstream myfile1 (argv[1]);
	int i,j,k,l,counter,arg,count,m;
	if (myfile1.is_open())
	{
		while(!myfile1.eof())
		{
			memset(argument,0,(int)(sizeof(argument)/sizeof(argument[0])));
			memset(command_char_array,0,(int)(sizeof(command_char_array)/sizeof(command_char_array[0])));
			i=0;j=0;k=0;l=0;counter=0;arg=0;count=0;
			getline (myfile1,line);
			if(line!=""){
				while((line[i]!=' ')&&(line[i]!='\0'))
				{
					command_char_array[j]=line[i];
					i++;
					j++;
				}
				j=0;day=0;hour=0;m=i;
				command=command_char_array;
				if(line[i]==' ')
				{
					i++;
					if(line[i]!='"')
					{
						if(command=="ADD")
						{
							printf("Invalid title\n");
							k++;
						}
					}
					else
					{
						argument[j]='"';
						i++;j++;
					}
					while(line[i]!='"'&&line[i]!='\0')
					{
						argument[j]=line[i];
						i++;j++;
					}
					if(line[i]=='"')
					{
						argument[j]=line[i];
						arg=i+1;
						while(line[arg]!='\0')
						{
							if(line[arg]==' ')
								count++;
							arg++;

						}
						if(count==2){

							i+=2;
							while(line[i]!=' ')
							{
								if(((int)(line[i]-48)>=0)&& ((int)(line[i]-48)<=9))
								{
									day=(day*10)+(line[i]-48);
								}
								else
								{
									printf("Invalid day\n");
									l++;
								}
								i++;
							}
							DAY=day;
							if ((!((day <=365) && (day >=1)))&&(l==0))
							{
								printf("Invalid day\n");
								l++;
							}
							i++;
							while(line[i]!='\0')
							{
								if(((int)(line[i]-48)>=0)&& ((int)(line[i]-48)<=9))
								{
									hour=(hour*10)+(line[i]-48);
								}
								else
								{
									printf("Invalid hour\n");
									l++;
								}
								i++;
							}
							HOUR=hour;
							if ((!((hour <=23) && (hour >=0)))&&(l==0))
							{
								printf("Invalid hour\n");
								l++;
							}


							if((l==0)&&k==0)
								if(command=="ADD")
									x.add_root(argument,day,hour,z);
						}
						else
							printf("Invalid arguments\n");
					}
					else
					{
						if(k==0)
						{
							if(command=="ADD")
							{
								printf("Invalid title\n");
								k++;
							}
						}

						i--;
						while(line[i]!=' ')
						{
							if(((int)(line[i]-48)>=0)&& ((int)(line[i]-48)<=9))
							{
								hour+=(line[i]-48)* pow(10,counter);
								counter ++;
							}
							else
							{
								printf("Invalid hour\n");
								l++;
							}
							i--;
						}
						HOUR=hour;
						if ((!((hour <=23) && (hour >=0)))&&(l==0))
						{
							printf("Invalid hour\n");
							l++;
						}
						i--; counter=0;
						while(line[i]!=' ')
						{
							if(((int)(line[i]-48)>=0)&& ((int)(line[i]-48)<=9))
							{
								day+=(line[i]-48)* pow(10,counter);
								counter ++;
							}
							else
							{
								printf("Invalid day\n");
								l++;
							}
							i--;
						}
						DAY=day;
						if ((!((day <=365) && (day >=1)))&&(l==0))
						{
							printf("Invalid day\n");
							l++;
						}
					}

				}
				if(command=="ADD"){}
				else if(command=="Print")
				{
					if(line[m]!=' ')
					{

						x.print(bt);

					}
					else
						printf("Invalid argument\n");
				}
				else if (command=="Find")
				{
					if ( line [m]==' ')
					{
						x.find(DAY,HOUR,y);
					}

					else
						printf("Invalid argument\n");
				}
				else if (command=="MOD")
				{
					if (line[m]==' ')
					{
						x.modify(DAY,HOUR,y,argument);
					}
					else
						printf("Invalid argument\n");

				}
				else if (command=="DEL")
				{
					if ( line [m]==' ')
					{
						x.del(DAY,HOUR,y);
					}

					else
						printf("Invalid argument\n");
				}
				else
				{
					printf("Invalid command\n");
				}

			}

		}
		myfile1.close();
	}
	else
	{
		printf("File not found \n");
	}

}




int main (int argc,char**argv) {
	if(argc==2)
	{
		read_command(argc,argv);
	}
	else
	{
		printf("File not Found\n");
	}




	return 0;
}





