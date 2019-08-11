/*************************************************
 *   G BRENT HURST
 *   RomanNumeralConverter.cpp
 *   May 7, 2017 (original)
 *   August 11, 2019 (last edit)
 *
 *   #include "RomanNumeralConverter.h"
 *
 ************************************************/


#include "RomanNumeralConverter.h"
#include <string>
#include <vector>
#include <set>

using namespace std;

//Self-explanatory
int SingleLetterConversion(char c)
{
	switch(c)
	{
		case 'I':
		case 'i': return 1;
		case 'V':
		case 'v': return 5;
		case 'X':
		case 'x': return 10;
		case 'L':
		case 'l': return 50;
		case 'C':
		case 'c': return 100;
		case 'D':
		case 'd': return 500;
		case 'M':
		case 'm': return 1000;
	}
	return -1;
}

//Self-explanatory
bool IsCharValid(char c)
{
	return (c=='I' || c=='V' || c=='X' || c=='L' || c=='C' || c=='D' || c=='M'
			|| c=='i' || c=='v' || c=='x' || c=='l' || c=='c' || c=='d' || c=='m');
}

//Self-explanatory
bool IsValidRN(const string& rn)
{
	unsigned int i;

	for(i=0; i<rn.size(); i++)
		if(!IsCharValid(rn[i]))
			return false;
	return true;
}

//Convert Roman numeral rn to decimal integer
//Return -1 if not valid Roman numeral
int RTI(const string& rn)
{
	int n;
	unsigned int i;
	vector<int> v;
	set<int> s;
	bool already;

	if(!rn.size() || !IsValidRN(rn))
		return -1;

	n=0;

	//insert into the set:
	s.insert(4);    //IV
	s.insert(9);    //IX
	s.insert(40);   //XL
	s.insert(90);   //XC
	s.insert(400);  //CD
	s.insert(900);  //CM

	for(i=0; i<rn.size(); i++)
	{
		//for each char, push back it's value onto v
		v.push_back(SingleLetterConversion(rn[i]));

		//if this val is bigger than the prev,
		//check if it's a valid Roman numeral
		if(i>0 && v[i]>v[i-1] && v[i-1] != 0)
		{
			if(already || s.find(v[i]-v[i-1])==s.end())
				return -1;
			already=true;
			v[i-1]=v[i]-v[i-1];
			v[i]=0;
		}
		else
			already=false;
	}

	for(i=0; i<rn.size(); i++)
		n+=v[i];

	return n;
}

//Return the majuscule Roman numeral
//form of an integer from 1 to 3999.
//Returns "" on n<1 or n>3999.
//Inconveniently long but self-explanatory.
string ITR(int n)
{
	string s;

	if(n<1 || n>3999)
		return "";

	s="";

	for(; n>=1000; n-=1000)
		s.push_back('M');

	if(n>=900)
	{
		s.push_back('C');
		s.push_back('M');
		n-=900;
	}

	if(n>=500)
	{
		s.push_back('D');
		n-=500;
	}

	if(n>=400)
	{
		s.push_back('C');
		s.push_back('D');
		n-=400;
	}

	for(; n>=100; n-=100)
		s.push_back('C');

	if(n>=90)
	{
		s.push_back('X');
		s.push_back('C');
		n-=90;
	}

	if(n>=50)
	{
		s.push_back('L');
		n-=50;
	}

	if(n>=40)
	{
		s.push_back('X');
		s.push_back('L');
		n-=40;
	}

	for(; n>=10; n-=10)
		s.push_back('X');

	if(n>=9)
	{
		s.push_back('I');
		s.push_back('X');
		n-=9;
	}

	if(n>=5)
	{
		s.push_back('V');
		n-=5;
	}

	if(n>=4)
	{
		s.push_back('I');
		s.push_back('V');
		n-=4;
	}

	for(; n>=1; n--)
		s.push_back('I');

	return s;
}

//Return the miniscule Roman numeral
//form of an integer from 1 to 3999.
//Returns "" on n<1 or n>3999.
string ITRL(int n)
{
	unsigned int i;
	string s;

	if(n<1 || n>3999)
		return "";

	s=ITR(n);
	for(i=0; i<s.size(); i++)
		s[i]+=('a'-'A');

	return s;
}
