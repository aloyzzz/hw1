/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main()  to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void insert (Node*& head, Node* newNode)
{
  if(head==nullptr)
  {head=newNode;}
  else {
    insert(head->next, newNode);
    }
}
void split(Node*& in, Node*& odds, Node*& evens)
{
  //Null Case
  if (in==nullptr) return;
  else  
  {
    Node* temp = in->next;
    in->next=NULL;
    if(in->value%2==0) // If Even
    {
      if(evens==NULL)
      {
        evens=in;
      }
      else 
      {
        insert(evens,in);
      }
    }
    else // If Odd
    {
      if(odds==NULL)
      {
        odds=in;
      }
      else {
        insert(odds,in);
      }
    }
    in=temp;
    split(temp,odds,evens);
  }
}

/* If you needed a helper function, write it here */
