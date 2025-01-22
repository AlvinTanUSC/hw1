/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;
int list[10];
int main(int argc, char* argv[])
{
  for(int i = 0; i < 10; i++)
    list[i] = i;
  Node* in = new Node(list[0], NULL);
  Node* temp = in;
  for(int i = 1; i < 10; i++){
    
    temp->next =new Node(list[i], NULL);
    temp = temp -> next;
  }
  temp = in;
  while(temp != NULL){
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
  Node* evens = NULL;
  Node* odds = NULL;

  split(in, odds, evens);
  temp = evens;
  while(temp != NULL){
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << endl;
  temp = odds;
  while(temp != NULL){
    cout << temp->value << " ";
    temp = temp->next;
  }
}
