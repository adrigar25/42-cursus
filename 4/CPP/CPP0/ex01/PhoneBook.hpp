#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook
{
  private:
	Contact contacts[8];

  public:
	PhoneBook(void);
	~PhoneBook();
	int add();
	int search();
};

#endif