// #include <_string.h>
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <string>
#include <iostream>

using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE


void ULListStr::push_back(const string& val)
{
  // base case
  if(tail_==nullptr)
  {
    Item* temp = new Item();
    head_=temp;
    tail_=temp;
    size_=1;
    numItems_=1;
    temp->val[0]=val;
    temp->last=1;
  }
  //If space in current item exists
  else if (tail_->last!=ARRSIZE)
  {
    tail_->val[tail_->last]=val;
    tail_->last++;
    // cout<<"Adding item at "<<tail_->last<<endl;
    size_++;
  }
  else if (tail_->last==ARRSIZE)
  {
    //If no more space in current item
    Item* temp = new Item();
    tail_->next=temp;
    temp->prev = tail_;
    tail_=temp;
    temp->val[0]=val;
    temp->last=1;
    size_++;
    numItems_++;
  }
}

void ULListStr::pop_back()
{
  //Do base case
  if (tail_==NULL) return;
  else if(tail_->last==1) //If we are on the last value in item
  {
    if(tail_==head_) //if it is the last item
    {
      delete tail_;
      head_=NULL;
      tail_=NULL;
      size_=0;
    }
    else{ // if it isnt the last item
    Item* newtail = tail_->prev;
    newtail->next=nullptr;
    delete tail_;
    tail_=newtail;
    size_--;
    }
  }
  else // Delete as usual
  {
    tail_->val[tail_->last-1]="";
    tail_->last--;
    size_--;
  }
}

void ULListStr::push_front(const string& val)
{
  //DO NULL CASE
  if (head_==nullptr)
  {
    Item* temp = new Item();
    head_=temp;
    tail_=temp;
    size_=1;
    numItems_=1;
    temp->val[0]=val;
    temp->last=1;
    // cout<<"Null Case"<<endl;
    //   cout<<"Size is "<<size_<<endl;
  }
  else if(head_->first!=0) // If head has space
  {
    head_->first--;
    head_->val[head_->first]=val;
    size_++;
    // cout<<"adding "<<val<<" to position "<<head_->first<<endl;
  }
  else if (head_->first==0) // If new head to be created
  {
    // cout<<"Adding new item conatiner"<<endl; 
    Item* temp = new Item();
    temp->next=head_;
    head_->prev=temp;
    head_=temp;
    head_->val[9]=val;
    head_->first=9;
    head_->last=10;
    size_++;
  }
  // cout<<"Size is "<<size_<<endl;
}

void ULListStr::pop_front()
{
  if (head_==NULL) return; //
  else if(head_->first==9)
  {
    if (size_==1) // IF last item
    {
      delete head_;
      head_=nullptr;
      tail_=nullptr;
      size_=0;
    }
    else{ //If there are more items
      Item* newhead = head_->next;
      delete head_;
      head_=newhead;
      head_->prev=nullptr;
      size_--;
    }
  }
  else // Delete as usual
  {
    head_->val[head_->first]="";
    head_->first++;
    size_--;
  }
}

const string& ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

const string& ULListStr::front() const
{
  return head_->val[head_->first];
}

string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc>=size_) return NULL;
  else
   {
    Item* temp = head_;
    int traversalsremainder = head_->last-head_->first;
    // cout<<"First Head Position is "<<head_->first<<endl;
    cout<<"Traversal Remainder is"<<traversalsremainder<<endl;
    // cout<<"We are here"<<endl;
    if(traversalsremainder-1>=loc) // If no traversals required
    {
      // cout<<"We are here2"<<endl;
      // cout<<"Checking location at "<<temp->first+loc<<endl;
      return&(temp->val[temp->first+loc]);
    }
    else{ // If traversals required
      // cout<<"We are here3"<<endl;
      int traversals = ((loc+1-traversalsremainder)/10)+1;
      if((loc+1-traversalsremainder)%10==0) traversals--;
      cout<<"Making "<<traversals<<" Traversals ";
      int valindex = (loc-traversalsremainder)%10;
      cout<<"Targeting "<<valindex<<" Index"<<endl;
      // if(valindex==0) traversals--;
      for(int i=0;i<traversals;i++)
      {
        temp=temp->next;
        // cout<<"Traversed "<<i<<endl;
      }
      // cout<<"adjacent values are "<<temp->val[valindex-1]<<endl;
      return &(temp->val[valindex]);
    }
    
   }
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

