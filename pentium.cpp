#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <map>
#include <climits>
using namespace std;
void pass1();
bool isSpace(char s);
void parse(string a,string word[],int &count);
bool isSpace(char s);


string opcode[100];

#include "optab.cpp"

ifstream fin1;
ofstream fout1,list;

FILE *f1,*f2,*f3;

//#include "Pass1.cpp"




void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        //swap(*(str[start]), *(str[end]));
        start++;
        end--;
    }
}

// Implementation of itoa()
char* itoa(int num, char* str, int base)
{
    int i = 0;
    int isNegative = 0;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}

int main() {
        pass1();

       return 0;


}

void pass1()
{
	 create_the_optab();
         char ch;string s,word[5],op_code,o,l,con;
	 int count=0,addr,z,length;int it;
	 char b[33],ch1;string address;
	 f1=fopen("input.txt","r");
	// f2=fopen("symtab.txt","w");
	 fin1.open("input.txt");
	// fout1.open("INTERMED.txt");
	 list.open("LIST.txt");

	list<<"Loc  \t\tSource code Instructions\t\tObject Code"<<endl;
    list<<"------------------------------------------------------------"<<endl<<endl;
	 while(fin1.is_open()){
	//This is going infinite.
	 getline(fin1,s);

	  parse(s,word,count);



 if(word[0]=="end")
		{
		break;

		}



	 if(word[0] == "_start")
          {

		addr=0;

		itoa(addr,b,16);


		address=b;

          }

          else if(word[0]=="add")
		{

		addr=addr+OPTAB["ADD"].format;
		itoa(addr,b,16);
		address=b;
		//cout<<"Address of instruction in little endian format  " <<b<<endl;
		op_code=OPTAB["ADD"].opcode+"d8";
         cout<<op_code<<"^";

		}
	  else if(word[0]=="mov")
		{
		   l=word[1];                                                                      		     //cout<<"l="<<l<<endl;                                                                  		  addr=addr+OPTAB["MOV"].format;
		  itoa(addr,b,16);
		  // cout<<"Address of instruction in little endian format  " <<b<<endl;
		  address=b;
		  o=OPTAB["MOV"].opcode;
		  ch=o.at(1);ch1=ch;                                              //cout<<"ch"<<ch<<endl;
		  z=ch-'0';                                                      //cout<<"z1"<<z<<endl;
		  z=z +0;                                                       //cout<<"z2"<<z<<endl;// REGISTER["word[1]"];
		int i;i=REGISTER[l].num;                                         //cout<<"i="<<i<<endl;
		z=z+i;
		  itoa(z,b,16);
	                                                                      //cout<<"b111="<<b<<endl;
		o.erase(1);
		//o.at(1)=(char)(b);
		o=o+b;
		// itoa(word[2],b,16);
		//con='0';
		 op_code=o+word[2];
		op_code=op_code+"000000";


		//op_code=op_code+"000000";



                  cout<<op_code<<"^";

		                                                             // replace( o.begin(), o.end(), ch1, ch );
		                                                        //op_code=OPTAB["MOV"].opcode+REGISTER["word[1]"].num;
		 }
	/*  else if(word[0]=="pop")
		{
		  addr=addr+OPTAB["POP"].format;
		  itoa(addr,b,16);
		  address=b;
		  op_code=OPTAB["POP"].opcode+REGISTER["word[1]"].num
		 }
	 	*/

it=0;
opcode[it++]=op_code;

	list<<address<<"  \t "<<word[0]<<" "<<word[1]<<"                       \t\t"<<op_code<<endl;
	//getline(fin1,s),
}

}



bool isSpace(char s)
{
    if(s == ' ')  return true;
    if(s == '\t') return true;
	 if(s == ',') return true;
    return false;
}
/*===============PARSE EACH LINE====================*/
void parse(string a,string word[],int &count)
{
    int i;
    for(i=0;i<5;++i) word[i] = "";
    count = 0;
    i = 0;
    while(isSpace(a[i]) && i<a.size()) { ++i; continue; }
    if(i == a.size())   return;
    for( ; i<a.size(); )
    {
        while(isSpace(a[i]) && i<a.size()) { ++i; continue; }
        if(i == a.size()) break;
        for( ; !isSpace(a[i]) && i<a.size(); ++i) word[count] += a[i];
        ++count;
    }
}
