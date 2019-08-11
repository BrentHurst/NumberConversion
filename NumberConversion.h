/*************************************************
 *   G BRENT HURST
 *   RomanNumeralConverter.h
 *   May 7, 2017 (original)
 *   December 21, 2017 (last edit)
 *
 *   Convert an int to a Roman numeral
 *   (use ITRL() for lower case)
 *   or a Roman numeral to a decimal int.
 *   The number must be between 0 and 3999.
 *
 *   Return values
 *     string ITR()
 *       string of the Roman numeral (majuscule)
 *       empty string if n>3999 or n<1
 *     string ITRL()
 *       string of the Roman numeral (miniscule)
 *       empty string if n>3999 or n<1
 *     int RTI()
 *       integer of the Roman numeral (decimal)
 *       -1 if not a valid Roman numeral
 *
 *   Code in RomanNumeralConverter.cpp
 *
 ************************************************/

#ifndef ROMANNUMERALCONVERTER_H
#define ROMANNUMERALCONVERTER_H


#include <string>

using namespace std;

string ITR(int);
string ITRL(int);
int RTI(const string&);

#endif
