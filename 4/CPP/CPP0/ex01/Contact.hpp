#ifndef CONTACT_H
# define CONTACT_H

# include <string>
class Contact
{
  private:
	std::string fname;
	std::string lname;
	std::string nick;
	std::string darkestSecret;
	int nbr;

  public:
	Contact();
	Contact(std::string fn, std::string ln, std::string nn, std::string ds,
		int nb);
	~Contact();
	std::string getFirstName();
	std::string getLastName();
	std::string getNickName();
	std::string getDarkestSecret();
	int getPhoneNumber();
	void setFirstName(std::string fn);
	void setLastName(std::string ln);
	void setNickName(std::string nn);
	void setDarkestSecret(std::string ds);
	void setPhoneNumber(int nb);
};

#endif