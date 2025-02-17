#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
#include <stdexcept>
#include <algorithm>
using std::invalid_argument; using std::runtime_error; using std::out_of_range;
#include <vector>
using std::string; using std::vector;
#include<functional>
using std::multiplies; using std::minus; using std::plus;
#include<numeric>
using std::accumulate;
#include <fstream>
#include<stdio.h> 
#include<string.h> 

int comp_func(vector<char> vec1, vector<char> vec2){
  if (vec1.size() < vec2.size()){
    std::swap(vec1,vec2);
  }
  int net = vec1.size() - vec2.size();
  for (int i = 0; i < static_cast<int>(vec2.size()); i++) {
    if (vec1[i] != vec2[i]){
      net += 1;
    }
  }
  return net;
}

int main(){
  string password;
  cout << "Give me a password:" << endl;
  cin >> password;
  cout << "You provided a password of " << password << endl;
  std::ifstream myfile;

	myfile.open("common_passwords.txt");
  vector<string> similar;
  vector<string> similar2;
  vector<char> pass_char(password.begin(), password.end());
  string fstring;
//hey nice code mannnnnnnnn
  int min = 10;
	while (true){
	   if (myfile >> fstring){
	      vector<char> compare(fstring.begin(), fstring.end());
        int limit = comp_func(pass_char, compare);

        if (min >= limit){
          min = limit;
          similar.push_back(fstring);
        }
	   }else if(myfile.eof()){
	   	break;
	   }
  }
  for(int i = 0; i < static_cast<int>(similar.size()); i++){
    vector<char> compare(similar[i].begin(), similar[i].end());
    int limit = comp_func(pass_char, compare);
    if(limit == min){
      similar2.push_back(similar[i]);
    }
	}


  //int change = compare(pass_char, compare);


  cout << "The most similar passwords to " << password << " are:" << endl;
  std::sort(similar2.begin(), similar2.end());
  for(int j = 0; j < static_cast<int>(similar2.size()); j++) {
		std::cout<< similar2[j] << ", ";
  }
  cout << endl << "All of which are " << min <<  " character(s) different.";
}

