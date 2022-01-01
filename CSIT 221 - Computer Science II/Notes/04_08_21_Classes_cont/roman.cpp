#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "roman.h"
using namespace std;

int objCounter = 0;

romanType::romanType() {
  romanNum = "";
  num = 0;
  objCounter++;
}

romanType::romanType(string str) {
  romanNum = str;
  num = 0;
  objCounter++;
}

void romanType::setRoman(string str) {
  romanNum = str;
}

void romanType::romanToPositiveInteger() {
  map<char, int> m;
  m.insert({ 'I', 1 });
  m.insert({ 'V', 5 });
  m.insert({ 'X', 10 });
  m.insert({ 'L', 50 });
  m.insert({ 'C', 100 });
  m.insert({ 'D', 500 });
  m.insert({ 'M', 1000 });

  for(int i = 0; i < romanNum.length(); i++) {
    if(m[romanNum[i]] < m[romanNum[i + 1]]) {
      num += m[romanNum[i + 1]] - m[romanNum[i]];
      continue;
    }
    num += m[romanNum[i]];
  }
}

void romanType::printPositiveInteger() {
  cout << num << endl;
}

void romanType::printRoman() {
  cout << romanNum << endl;
}