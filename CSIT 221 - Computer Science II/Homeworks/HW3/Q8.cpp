//Chp 12, Q8
#include <iostream>
#include <string>
using namespace std;


int main() {
  string str1 = "sunny";
  string str2 = "cloudy";
  string *s1;

  //since str1 and str2 are simply the strings "sunny" and "cloudy", respectively, the following statement outputs the string: "sunny cloudy"
  cout << str1 << " " << str2 << endl;


  s1 = &str1;   //the pointer s1 now points to the memory location of str1
  str1 = str2;   //then, the value of str1 becomes the value of str2, meaning str1 is now the string "cloudy"
  str2 = *s1;   //finally, the value of str2 becomes the value stored in the memory location of str1 (since the pointer s1 stores the memory location of str1), but because of the previous command, str2 is still the string "cloudy"

  //the following statement outputs the string: "cloudy cloudy"
  cout << str1 << " " << str2 << endl;


  return 0;
}