#pragma once
#ifndef _STUDENT_H_  
#define _STUDENT_H_  

#include <iostream>  
#include <string>  
#include <iomanip>  
#include <stdexcept>  
using namespace std;

class Date_Exception :public logic_error {
private:
	int var_;
public:
	Date_Exception(int var) :logic_error("��������ֵ!")
	{
		var_ = var;
	}
	double getSide() const { return var_; }
};

class Date {
private:
	int year_;
	int month_;
	int day_;
public:
	Date() :year_(0), month_(0), day_(0) {}
	Date(int year, int month, int day)
	{
		year_ = year;
		month_ = month;
		day_ = day;
	}
	void setDate(int year, int month, int day)
	{
		if (year < 1990 || year>2016)
			throw Date_Exception(year);
		year_ = year;
		if (month < 1 || month>12)
			throw Date_Exception(month);
		month_ = month;
		if (day < 1 || day>31)
			throw Date_Exception(day);
		day_ = day;
	}
	int getYear() const { return year_; }
	int getMonth() const { return month_; }
	int getDay() const { return day_; }
};

class Student {
private:
	string name_;//����  
	int number_;//ѧ��  
	string sex_;//�Ա�  
	Date date_;//��������  
	string address_;//סַ  
	string native_place_;//����  
public:
	//default value("Andy", 1, "��"��date, "����", "����")  
	Student() :name_("Andy"), number_(1), sex_("��"), date_(0, 0, 0), address_("����"), native_place_("����") {}
	Student(string name, int number, string sex, Date date, string address, string native_place);

	void setStudent(string name, int number, string sex, Date date, string address, string native_place);
	void setSex(string sex) { sex_ = sex; }
	void setDate(Date date) { date_ = date; }
	void setAddress(string address) { address_ = address; }
	void setNativePlace(string native_place) { native_place = native_place; }

	string getName() const { return name_; }
	int getNumber() const { return number_; }
	string getSex() const { return sex_; }
	Date getDate() const { return date_; }
	string getAddress() const { return address_; }
	string getNativePlace() const { return native_place_; }

	bool operator ==(Student &other);
	Student& operator =(Student &other);
	friend ostream &operator <<(ostream &out, const Date &other);
	friend istream &operator >>(istream &in, Date &other);
	void printStudent();
};

ostream &operator <<(ostream &out, const Date &other);
istream &operator >>(istream &in, Date &other);

#endif // !_STUDENT_H  
