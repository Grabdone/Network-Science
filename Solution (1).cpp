
/*
Saad Yousaf
bscs16.092-B
*/
#include<iostream>
using namespace std;
#include<ctype.h>
#include<string.h>

//Functions to calculate Follow 
void followfirst(char, int, int); 
void follow(char c);



void findfirst(char, int, int);

int val = 0;
int n = 0;


char calc_first[10][100];


char calc_follow[10][100];
int m = 0;

char production[10][10];
char f[10], first[10];
int k;
char ck;
int e;

int main(int argc, char **argv)
{
	int count = 10;
	int jm = 0;
	int km = 0;
	int i, choice;
	char c, ch;
	val = count;


	strcpy(production[0], "S=ABCDE");
	strcpy(production[1], "A=a");
	strcpy(production[2], "B=b");
	strcpy(production[3], "C=c");
	strcpy(production[4], "D=d");
	strcpy(production[5], "E=e");
	strcpy(production[6], "A=@");
	strcpy(production[7], "B=@");
	strcpy(production[8], "D=@");
	strcpy(production[9], "E=@");



	int kay;
	char done[10];
	int ptr = -1;

	// Initializing the calc_first array 
	for(k = 0; k < count; k++) { 
		for(kay = 0; kay < 100; kay++) { 
			calc_first[k][kay] = '!'; 
		} 
	} 

	
	int point1 = 0;
	int point2 = 0;
	int xxx = 0;

	for (k = 0; k < count; k++)
	{
		c = production[k][0];
		point2 = 0;
		xxx = 0;


		for (kay = 0; kay <= ptr; kay++)
		if (c == done[kay])
			xxx = 1;

		if (xxx == 1)
			continue;


		findfirst(c, 0, 0);
		ptr += 1;


		done[ptr] = c;
		printf("\n First Grammer(%c) = { ", c);
		calc_first[point1][point2++] = c;

		for (i = 0 + jm; i < n; i++) {
			int a = 0, b = 0;

			for (a = 0; a < point2; a++) {

				if (first[i] == calc_first[point1][a])
				{
					b = 1;
					break;
				}
			}
			if (b == 0)
			{
				printf("%c, ", first[i]);
				calc_first[point1][point2++] = first[i];
			}
		}
		printf("}\n");
		jm = n;
		point1++;
	}
	printf("\n");
	printf("-----------------------------------------------\n\n");



	char donee[10]; 
	ptr = -1; 
	
	// Initializing the calc_follow array 
	for(k = 0; k < count; k++) { 
		for(kay = 0; kay < 100; kay++) { 
			calc_follow[k][kay] = '!'; 
		} 
	} 
	point1 = 0; 
	int land = 0; 
	for(e = 0; e < count; e++) 
	{ 
		ck = production[e][0]; 
		point2 = 0; 
		xxx = 0; 
		
		// Checking if Follow of ck 
		// has alredy been calculated 
		for(kay = 0; kay <= ptr; kay++) 
			if(ck == donee[kay]) 
				xxx = 1; 
				
		if (xxx == 1) 
			continue; 
		land += 1; 
		
		// Function call 
		follow(ck); 
		ptr += 1; 
		
		// Adding ck to the calculated list 
		donee[ptr] = ck; 
		printf(" Follow(%c) = { ", ck); 
		calc_follow[point1][point2++] = ck; 
		
		// Printing the Follow Sets of the grammar 
		for(i = 0 + km; i < m; i++) { 
			int lark = 0, chk = 0; 
			for(lark = 0; lark < point2; lark++) 
			{ 
				if (f[i] == calc_follow[point1][lark]) 
				{ 
					chk = 1; 
					break; 
				} 
			} 
			if(chk == 0) 
			{ 
				printf("%c, ", f[i]); 
				calc_follow[point1][point2++] = f[i]; 
			} 
		} 
		printf(" }\n\n"); 
		km = m; 
		point1++; 
	} 
}


void followfirst(char c, int c1, int c2) 
{ 
	int k; 
	int count = 10;
	val = count;
	// The case where we encounter 
	// a Terminal 
	if(!(isupper(c))) 
		f[m++] = c; 
	else
	{ 
		int i = 0, j = 1; 
		for(i = 0; i < count; i++) 
		{ 
			if(calc_first[i][0] == c) 
				break; 
		} 
		
		//Including the First set of the 
		// Non-Terminal in the Follow of 
		// the original query 
		while(calc_first[i][j] != '!') 
		{ 
			if(calc_first[i][j] != '@') 
			{ 
				f[m++] = calc_first[i][j]; 
			} 
			else
			{ 
				if(production[c1][c2] == '\0') 
				{ 
					// Case where we reach the 
					// end of a production 
					follow(production[c1][0]); 
				} 
				else
				{ 
					// Recursion to the next symbol 
					// in case we encounter a "#" 
					followfirst(production[c1][c2], c1, c2+1); 
				} 
			} 
			j++; 
		} 
	} 
} 

void findfirst(char c, int q1, int q2)
{
	int j;


	if (!(isupper(c))) {
		first[n++] = c;
	}
	for (j = 0; j < val; j++)
	{
		if (production[j][0] == c)
		{
			if (production[j][2] == '@')
			{
				if (production[q1][q2] == '\0')
					first[n++] = '@';
				else if (production[q1][q2] != '\0'
					&& (q1 != 0 || q2 != 0))
				{

					findfirst(production[q1][q2], q1, (q2 + 1));
				}
				else
					first[n++] = '@';
			}
			else if (!isupper(production[j][2]))
			{
				first[n++] = production[j][2];
			}
			else
			{

				findfirst(production[j][2], j, 3);
			}
		}
	}
}
void follow(char c) 
{ 
	int i, j; 
	
	// Adding "$" to the follow 
	// set of the start symbol 
	if(production[0][0] == c) { 
		f[m++] = '$'; 
	} 
	for(i = 0; i < 10; i++) 
	{ 
		for(j = 2;j < 10; j++) 
		{ 
			if(production[i][j] == c) 
			{ 
				if(production[i][j+1] != '\0') 
				{ 
					// Calculate the first of the next 
					// Non-Terminal in the production 
					followfirst(production[i][j+1], i, (j+2)); 
				} 
				
				if(production[i][j+1]=='\0' && c!=production[i][0]) 
				{ 
					// Calculate the follow of the Non-Terminal 
					// in the L.H.S. of the production 
					follow(production[i][0]); 
				} 
			} 
		} 
	} 
} 