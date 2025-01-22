#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
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
void ULListStr::push_back(const std::string& val)
{

  if(tail_ == NULL){
    Item* temp = new Item();
    temp -> prev = tail_;
    temp->val[temp->last] = val;
    (temp->last)++;
    tail_ = temp;
    head_ = temp;
    
  } else if (tail_->last == ARRSIZE){
    Item* temp = new Item();
    temp -> prev = tail_;
    temp->val[temp->last] = val;
    (temp->last)++;
    tail_->next = temp;
    tail_ = temp;
  }else {
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
}
void ULListStr::pop_back()
{
  if(tail_ == NULL)
    return;
  (tail_->last)--;
  if(tail_->last == tail_->first){
    Item* temp = tail_->prev;
    delete tail_;
    tail_ = temp; 
    if(tail_ == NULL)
      head_ = NULL;
    else
      tail_->next = NULL;
  }
  size_--;
}

void ULListStr::push_front(const std::string& val)
{
  if(head_ == NULL || head_->first == 0){
    Item* temp = new Item();
    temp -> next = head_;
    temp->val[ARRSIZE-1] = val;
    temp->last = ARRSIZE;
    temp->first = ARRSIZE - 1;
    if(head_ != NULL)
      head_->prev = temp;
    head_ = temp;
    if(tail_ == NULL)
      tail_ = temp;
    
  } else {
    head_->val[head_->first - 1] = val;
    head_->first--;
  }
  size_++;
}

void ULListStr::pop_front()
{
  if(head_ == NULL)
    return;
  head_->first++;
  if(head_->last == head_->first){
    Item* temp = head_->next;
    
    delete head_;
    head_ = temp;
    
    
    if(head_ == NULL)
      tail_ = NULL;
    else
      temp->prev = NULL;
  }
  size_--;
}

std::string const & ULListStr::back() const{
  if(tail_ == NULL)
    return NULL;
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const{
  if(head_ == NULL)
    return NULL;
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc > size_ || loc < 0)
    return NULL;
  Item* temp = head_;

  while(temp != NULL && loc >= (temp->last - temp->first)){
   
  loc -= temp->last - temp->first;
  temp = temp->next;
  }
  if(temp == NULL)
    return NULL;
  return &(temp->val[temp->first + loc]);
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
