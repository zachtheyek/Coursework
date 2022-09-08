#include <iostream>
#include <vector> //STL vector

/*
  Write a function that prints from x to y
  using a loop (for or while)
*/

void print_count_iterative(int start, int stop){
  //START: start
  //STOP: stop
  //STEP: 1
  for(int i=start;i<stop;i++)
    std::cout << i << " ";
}

void print_count_recursive(int start, int stop){
  if(start != stop){ //STOP-CASE
    std::cout << start << " ";
    print_count_recursive(start+1, stop);
  }
}

void print_vector_iterative(std::vector<int> L){
  //for(int i=0; i<L.size(); i++)
  //  std::cout << L[i] << " ";
  //Alternative 1
  for(int i : L)
    std::cout << i << " ";
  
  std::cout<< std::endl;
}

//ughw 9/6
//Implement recursive print_vector_recursive fn 
void print_vector_recursive(std::vector<int> L, int i) {				
				if(i == L.size()) // base case
						return;
				std::cout << L[i] << " ";
				print_vector_recursive(L, i + 1);
}

int main() {
  
  //print_count_iterative(10,20);
  //print_count_recursive(10,20);

  std::vector<int> L = {3,1,8,5,3,9};
  print_vector_iterative(L);
  print_vector_recursive(L, 0);
  
}
