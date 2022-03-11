/*
 * Idenitfy all the memory bugs and potential bugs in this code
 */

#include <string>

struct Student {
  std::string name_;
  std::uint64_t phone_;
  Student* next_;
};

void delete_list1(Student* head)  // Bad: Only deleting the pointer, should delete all elements before deleting the pointer
{
  delete head;
}

void delete_list2(Student* head)   // Bad: Deletes the pointer and then tries to access where the pointer goes to
{
  while(head) {
    delete head;
    head = head->next_;
  }
}

void delete_list3(Student* head)  // Bad: This will break when passed Null
{
  while(head->next_) {
    delete head;
    head = head->next_;
  }
}

void delete_list4(Student* head)  // Bad: this function will not delete a list size of 1
{
  while(head->next_) {
    Student* tmp = head->next_;
    delete head;
    head = tmp;
  }
}

void delete_list5(Student* head)  // Bad? 
{
  if (!head) {
    return;
  }
  while(head->next_) {
    Student* tmp = head->next_;
    delete head;
    head = tmp;
  }
  delete head;
}

void delete_list6(Student* head)  // Bad? tries to delete an array which is not what head is
{
  if (!head) {
    return;
  }
  while(head->next_) {
    Student* tmp = head->next_;
    delete head;
    head = tmp;
  }
  delete[] head;
}

void delete_list7(Student* head)  // Bad? tmp should be a pointer to the next item, not an auto value
{
  if (!head) {
    return;
  }

  while(head->next_) {
    auto tmp = head->next_;
    delete head;
    head = tmp;
  }
  delete head;
}

void delete_list8(Student* head) // Bad? this one works
{
  if (!head) return;
  if (!head->next_) delete head;
  else delete_list8(head->next_);
}

////////////////////////////////////////////////////////////////////////

int main()
{
  Student* lst;
  lst->name_ = "whoami"; // Bad: it points to the structure, not calling for new space
  delete lst;            // Bad: trying to delete something that hasnt been initialized
  delete_list1(lst);     // Bad: same as above, but also lst is uninitialized

  lst = new Student({ "Joe", 1234, nullptr });
  delete_list1(lst);    // Bad: delete list1 is broken

  lst = new Student({ "Joe", 1234, nullptr });
  lst = new Student({ "Jolene", 4321, nullptr });  // Bad:
  delete_list2(lst);    // Bad:
  delete_list3(lst);    // Bad:

  lst = new Student({ "Jolene", 7332578, nullptr });
  delete_list3(lst);    // Bad:

  lst = new Student({ "Jeremy", 1, nullptr }); // Bad?
  lst = new Student({ "Jolene", 90554, new Student() }); // Bad?
  lst->name_ = "Joel";  // Bad?

  lst->next_->name_ = "Jill";   // Bad?
  lst->next_->next_->name_ = "Jack";  // Bad?

  delete_list2(lst);  // Bad?
  delete_list3(lst);  // Bad?
  delete_list4(lst);  // Bad?
  delete_list5(lst);  // Bad?
  delete_list6(lst);  // Bad?
  delete_list7(lst);  // Bad?
  delete_list8(lst);  // Bad?
  delete_list8(lst->next_);  // Bad?


  return 0;
}
