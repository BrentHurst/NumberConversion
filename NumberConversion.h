/*************************************************
 *   G BRENT HURST
 *   RomanNumeralConverter.h
 *   May 7, 2017 (original)
 *   August 12, 2019 (last edit)
 *
 *   Convert an int to a Roman numeral
 *   or a Roman numeral to a decimal int.
 *   The number must be between 0 and 3999.
 *
 *   Return values
 *     string ToRomanUpper()
 *       string of the Roman numeral (majuscule)
 *       empty string if n>3999 or n<1
 *     string ToRomanLower()
 *       string of the Roman numeral (miniscule)
 *       empty string if n>3999 or n<1
 *     int FromRoman()
 *       integer of the Roman numeral (decimal)
 *       -1 if not a valid Roman numeral
 *
 ************************************************/

#ifndef NUMBERCONVERSION_H
#define NUMBERCONVERSION_H


#include <string>

using namespace std;

string ToRomanUpper(int);
string ToRomanLower(int);
int FromRoman(const string&);

#endif
