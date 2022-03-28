//============================================================================
// Name        : A1.cpp
// Author      : mohamed sayed mohamed mohamed ahmed
// Description : Assignment one
//============================================================================

#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;


void print(int argc,char** argv)
{
	for(int i=2;i<argc;i++)
		printf("%s ",argv[i]);
	printf("\n");
}

void upper(int argc,char** argv)
{

	for(int i=2;i<argc;i++)
	{
		char word[(int)strlen(argv[i])];
		strcpy(word, argv[i]);
		char w;
		for(int j=0;j<=((int)strlen(argv[i])-1);j++)
		{
			w=toupper(word[j]);
			cout<<w;
		}
		printf(" ");

	}
}

void shuffle(int argc,char** argv)

{
	if(argc>3)
	{
		printf("Incorrect Number of Arguments \n");
	}
	else {
		string word=argv[2];
		char a;
		for(int i=0;(i+1)<(int)strlen(argv[2]);i+=2)
		{
			a=word[i];
			word[i]=word[i+1];
			word[i+1]=a;
		}
		cout << word;

	}}

void shuffleStatement(int argc,char** argv)
{
	char ** arg=argv;
	char*a;
	for(int i=2;i<(argc-1);i+=2)
	{
		a=arg[i];
		arg[i]=arg[i+1];
		arg[i+1]=a;
	}
	print(argc,arg);
}

void delet(int argc,char** argv)
{
	char **arg=argv;
	int b=atoi(arg[2]);
	int a=2+b;
	//cout<<atoi(argv[2])<<endl;

	if((a<argc)&&(int(*argv[2]))!=48)
	{
		if(!(atoi(argv[2])<=0))
		{
			for(int i=a;i<argc;i++)
			{
				arg[i]=arg[i+1];
			}
			char* ar[argc-1];
			for(int i=2;i<(argc-1);i++)
			{
				ar[i]=arg[i];
			}
			for(int i=3;i<argc-1;i++)
				printf("%s ",ar[i]);
			printf("\n");
		}
		else printf("Incorrect Data Type \n") ;
	}
	else  printf("Incorrect Number of Arguments \n");

}


void middle(int argc,char** argv)
{
	if(argc%2==0)
	{
		printf("%s %s \n",argv[((argc-1)/2)+1],argv[((argc-1)/2)+2]);
	}
	else printf("%s \n",argv[((argc-1)/2)+1]);

}

void reverse(int argc,char** argv)
{
	for(int i=(argc-1);i>1;i--)
		printf("%s ",argv[i]);
	printf("\n");
}

char add(int argc,char** argv)
{
	int sum=0;

	for(int i=2;i<argc;i++)
	{
		char word[(int)strlen(argv[i])];
		strcpy(word, argv[i]);

		for(int j=0;j<=(int)strlen(argv[i]);j++)
		{if(  ( (  word[j] -48 ) >9 ))
		{
			printf("Incorrect Data Type \n");
			return 0;
		}
		}
		sum+=atoi(argv[i]);
	}
	printf("%d \n",sum);
	return 0;
}


void random(int argc,char** argv)
{char j=0;

if(argc==6)
{
	if(!(atoi(argv[3])>=atoi(argv[4])))
	{
	for(int i=2;i<argc;i++)
	{ if(atoi(argv[i])==0)  {j++;  break;}}
	if((j>0)||(atoi(argv[2])<0)) printf("Incorrect Data Type \n") ;
	else
	{
		srand(atoi(argv[5]));
		int ran;
		for (int i = 0; i < atoi(argv[2]); i++)
		{
			ran = (rand() % (atoi(argv[4]) - atoi(argv[3])  + 1) )+ atoi(argv[3]);

			printf("%d ", ran);
		}
	}

}
	else
		printf("Incorrect Data Type \n");
}
else printf("Incorrect Number of Arguments \n");



}





int main(int argc,char**argv)
{
	if(argc>1)
	{
		if(!strcmp(argv[1],"print"))
		{
			if(argc>2)
			{
				print(argc,argv);
			}
			else
				printf("Incorrect Number of Arguments \n");
		}

		else if (!strcmp(argv[1],"upper"))
		{
			if(argc>2)
			{
				upper(argc,argv);
			}
			else
				printf("Incorrect Number of Arguments \n");
		}

		else if (!strcmp(argv[1],"shuffle"))
		{
			if(argc>2)
			{
				shuffle(argc,argv);
			}
			else
				printf("Incorrect Number of Arguments \n");
		}
		else if (!strcmp(argv[1],"shuffleStatement"))
		{
			if(argc>2)
			{
				shuffleStatement(argc,argv);
			}
			else
				printf("Incorrect Number of Arguments \n");
		}

		else if (!strcmp(argv[1],"delete"))
		{
			if(argc>2)
			{
				delet(argc,argv);
			}
			else
				printf("Incorrect Number of Arguments \n");
		}

		else if (!strcmp(argv[1],"middle"))
		{
			if(argc>2)
			{
				middle(argc,argv);
			}
			else
				printf("Incorrect Number of Arguments \n");
		}

		else if (!strcmp(argv[1],"reverse"))
		{
			if(argc>2)
			{
				reverse(argc,argv);
			}
			else
				printf("Incorrect Number of Arguments \n");
		}
		else if (!strcmp(argv[1],"add"))
		{

			if(argc>2)
			{
				add(argc,argv);
			}
			else
				printf("Incorrect Number of Arguments \n");

		}
		else if (!strcmp(argv[1],"random"))
		{

			if(argc>2)
			{
				random(argc,argv);
			}
			else
				printf("Incorrect Number of Arguments \n");

		}
		else
		{
			printf("Undefined Command \n");
		}
	}
	else
	printf("Undefined Command \n");


	return 0;
}

