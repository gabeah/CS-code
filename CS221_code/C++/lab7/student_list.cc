/*
 * Idenitfy all the memory bugs and potential bugs in this code
 */

#include <string>

struct Student {
  std::string name_;
  std::uint64_t phone_;
  Student* next_;
};

void delete_list1(Student* head)  // Bad:
{
  delete head;
}

void delete_list2(Student* head)   // Bad:
{
  while(head) {
    delete head;
    head = head->next_;
  }
}

void delete_list3(Student* head)  // Bad:
{
  while(head->next_) {
    delete head;
    head = head->next_;
  }
}

void delete_list4(Student* head)  // Bad:
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

void delete_list6(Student* head)  // Bad?
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

void delete_list7(Student* head)  // Bad?
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

void delete_list8(Student* head) // Bad?
{
  if (!head) return;
  if (!head->next_) delete head;
  else delete_list8(head->next_);
}

////////////////////////////////////////////////////////////////////////

int main()
{
  Student* lst;
  lst->name_ = "whoami"; // Bad:
  delete lst;            // Bad:
  delete_list1(lst);     // Bad:

  lst = new Student({ "Joe", 1234, nullptr });
  delete_list1(lst);    // Bad:

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
