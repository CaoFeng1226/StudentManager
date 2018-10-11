#include "Student.h"  

Student::Student(string name, int number, string sex, Date date, string address, string native_place) :name_(name),
number_(number), sex_(sex), date_(date), address_(address), native_place_(native_place) { }

void Student::setStudent(string name, int number, string sex, Date date, string address, string native_place)
{
	name_ = name;
	number_ = number;
	sex_ = sex;
	date_ = date;
	address_ = address;
	native_place_ = native_place;
}

bool Student::operator ==(Student &other)
{
	return (name_ == other.name_&&number_ == other.number_&&sex_ == other.sex_);
}

Student& Student::operator=(Student &other)
{
	name_ = other.name_;
	number_ = other.number_;
	sex_ = other.sex_;
	date_ = other.date_;
	address_ = other.address_;
	native_place_ = other.native_place_;
	return *this;
}

ostream &operator <<(ostream &out, const Date &other)
{
	out << other.getYear() << "-" << other.getMonth() << "-" << other.getDay();
	return out;
}

istream &operator >>(istream &in, Date &other)
{
	int year, month, day;
	in >> year >> month >> day;
	other.setDate(year, month, day);
	return in;
}

void Student::printStudent()
{
	cout << name_ << setw(6) << number_ << setw(6) << sex_ << setw(9) << date_ << setw(12) << address_ << setw(12) << native_place_ << endl;
}
