#include "./Contact.hpp"

Contact::Contact() : fname(""), lname(""), nick(""), darkestSecret(""), nbr(0)
{
}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string ds,
	int nb) : fname(fn), lname(ln), nick(nn), darkestSecret(ds), nbr(nb)
{
}

Contact::~Contact()
{
}

std::string Contact::getFirstName(void)
{
	return (fname);
}

void Contact::setFirstName(std::string fn)
{
	fname = fn;
}

std::string Contact::getLastName(void)
{
	return (lname);
}

void Contact::setLastName(std::string ln)
{
	lname = ln;
}

std::string Contact::getNickName(void)
{
	return (nick);
}

void Contact::setNickName(std::string nn)
{
	nick = nn;
}

std::string Contact::getDarkestSecret(void)
{
	return (darkestSecret);
}

void Contact::setDarkestSecret(std::string ds)
{
	darkestSecret = ds;
}

int Contact::getPhoneNumber(void)
{
	return (nbr);
}

void Contact::setPhoneNumber(int nb)
{
	nbr = nb;
}
