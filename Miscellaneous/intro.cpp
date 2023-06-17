#include <cstdio>
#include <iostream>
#include <algorithm>
#include<map>
#include<unordered_map>
#include <cmath>
#include<string>
#include<set>
#include <vector>

// Q. given an array remove minimum number of elements such that the in resultant array the sum of every adjacent pair is even 
// {a, b, c, d} adj pair = (a, b), (b, c), (c, d)

// Q. given an integer n. There is an array of size n + 1 which contains the coefficients of the polynomial of degree n
// find all the roots of this polynomial
// the order of precedence is + > * > ^  (reversed order of normal precedence)
// 0 ^ 0 = 1
// for evaluating power follow top to bottom rule i.e 2 ^ 3 ^ 2 = (2 ^ (3 ^ 2)) i.e. evaluate the top powers first

// Q. given a 2D array initially having all 0s
// given q queries of type (i, j), increment all the cells of submatrix whose top left is (0, 0) and bottom right is (i, j) by 1
// after answering all the queries, return the count of cells having maximum value in them 

using namespace std;

int solve(string &str){
  int n = str.length();

  // unordered_map<int, int> m;
  set<int> s;

  int num = 0;
  for(int i = 0; i < n; i++){
    if(isdigit(str[i])){
      num = num * 10 + str[i] - '0';
    }
    else{
      s.insert(num);
      num = 0;
    }
  }

  // for(int i = 0; i < n; i++){
  //   if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
  //     str[i] = ' ';
  //   }
  // }

  // for(int i = 0; i < n; i++){
  //   string temp;

  //   if(str[i] != ' '){
  //     temp += str[i];
  //   }
  //   else{

  //     int num;

  //     for(int i = 0; i < temp.length(); i++){
  //       num = num * 10 + temp[i] - '0';
  //     }

  //     s.insert(num);



  //     // if(temp != " ");
  //     //   m[stoi(temp)]++;
  //     // temp = "";
  //   }
  // }

  return s.size();


}

int main() {
  // Declare the variable
  string str;
  
  // Read the variable from STDIN
  cout << "Enter the string" << endl;
  cin >> str;

  cout << solve(str);
  
  return 0;
}
