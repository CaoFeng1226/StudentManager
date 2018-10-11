#include "Student.h"  
#include "interface.h"  
#include <iostream>  
#include <cstdlib>  
#include <iomanip>  
#include <fstream>  

using namespace std;
const int MAX = 200;//数组大小   

void menu_display();//显示菜单  
void print_students_info(Student *stu);//显示全体学生信息  
void read_student_info(Student *stu);//录入学生信息  
int search_by_number(Student *stu, const int num);//根据学号查询  
void search_by_name(Student *stu, const string name);//根据姓名查询 考虑重名  
void modify_student(Student *stu, int num, int choice);//修改学生信息  
void delete_student(Student *stu, int num);//删除学生信息  
void write_file(Student *stu, const string file_name);//保存到文件  

int main()
{
	Front();//开始的界面   

	Date date[4];
	date[1].setDate(1996, 2, 3);
	date[2].setDate(1995, 12, 1);
	date[3].setDate(1997, 6, 6);
	Student students[MAX];
	students[1].setStudent("徐一", 1, "男", date[1], "西安", "江苏");
	students[2].setStudent("刘二", 2, "女", date[2], "西安", "陕西");
	students[3].setStudent("张三", 3, "男", date[3], "西安", "浙江");

	int flag = 1;
	while (flag) {
		menu_display();
		cout << "输入你想执行的操作:";
		int ch;
		cin >> ch;
		switch (ch) {
		case 1:
		{			
			cout << endl;
			cout << "显示当前全体学生信息:" << endl;
			print_students_info(students);
			cout << endl;
			break;
		}

		case 2:
		{
			cout << endl;
			cout << "输入你想录入的学生信息:(学号根据当前学生人数自动排序)" << endl;
			read_student_info(students);
			cout << "显示当前全体学生信息:" << endl;
			print_students_info(students);
			cout << endl;
			break;
		}	

		case 3:
		{
			cout << endl;
			cout << "1.根据学号查询\t2.根据姓名查询\t3.退出:";
			int choice;
			cin >> choice;
			if (choice == 1) {
				cout << "请输入查找的学号:";
				int num;
				cin >> num;
				int i = search_by_number(students, num);
				if (i == 0)
					cout << "找不到此学生信息" << endl << endl;
				else {
					cout << "学生信息如下:" << endl;
					students[i].printStudent();
					cout << endl;
				}
			}
			else if (choice == 2) {
				cout << "请输入查找的姓名:";
				string name;
				cin >> name;
				search_by_name(students, name);
				cout << endl;
			}
			else {
				cout << endl;
				break;
			}
			break;
		}

		case 4:
		{
			cout << endl;
			cout << "请输入你想修改的学号:";
			int i;
			cin >> i;
			int n = 1;
			while (students[n].getName() != "Andy") {
				n++;
			}//求现在的学生人数  
			if (i > n - 1) {
				cout << "没有此学生信息!" << endl;
				cout << endl;
			}
			else {
				cout << "输入你想修改的属性(1.性别\t2.出生日期\t3.地址\t4.籍贯):";
				int no;
				cin >> no;
				modify_student(students, i, no);
				cout << "显示当前全体学生信息:" << endl;
				print_students_info(students);
				cout << endl;
			}
			break;
		}

		case 5:
		{
			cout << endl;
			cout << "请输入你想删除的学号:";
			int i0;
			cin >> i0;
			delete_student(students, i0);
			cout << "显示当前全体学生信息:" << endl;
			print_students_info(students);
			cout << endl;
			break;
		}

			
		case 6:
		{
			cout << endl;
			cout << "输入你想写入的文件名:";
			string file_name;
			cin >> file_name;
			write_file(students, file_name);
			cout << endl;
			break;
		}

		case 7:
		{
			cout << endl;
			cout << "退出系统!";
			cout << endl;
			flag = 0;
			break;
		}

		}//switch  
	}//while  
	cout << endl;

	Back();//结束界面   
	return 0;
}

void menu_display()
{
	for (int i = 0; i<10; i++)
		cout << "*";
	cout << "学生管理系统";
	for (int i = 0; i<10; i++)
		cout << "*";
	cout << endl;
	cout << "* 1.显示" << "\t\t" << "2.录入 *" << endl;
	cout << "* 3.查询" << "\t\t" << "4.修改 *" << endl;
	cout << "* 5.删除" << "\t\t" << "6.打印 *" << endl;
	cout << "* 7.退出" << "\t\t" << "       *" << endl;
	for (int i = 0; i<32; i++)
		cout << "*";
	cout << endl;
}

void print_students_info(Student *stu)
{
	int num = 1;
	while (stu[num].getName() != "Andy") {
		num++;
	}
	cout << "姓名" << "   " << "学号" << "  " << "性别" << setw(12) << "出生日期" << setw(12) << "地址" << setw(12) << "籍贯" << endl;
	for (int i = 1; i < num; i++) {
		if (stu[i].getName() == "无") {
			cout << endl;
			continue;
		}
		stu[i].printStudent();
	}
}

void read_student_info(Student *stu)
{
	string name, sex, address, native_place;
	Date date;
	cout << "姓名:";
	cin >> name;
	cout << "性别:";
	cin >> sex;
	try {
		cout << "出生日期:";
		cin >> date;
	}
	catch (Date_Exception &e) {
		cout << e.getSide() << e.what() << endl;
		cout << "是否要重新输入(y or n)";
		//char ch;
		int ch;
		cin >> ch;
		if (ch == 'y') {
			cout << "出生日期:";
			cin >> date;
		}
		else {
			cout << "录入信息失败!" << endl;
			return;
		}
	}
	cout << "地址:";
	cin >> address;
	cout << "籍贯:";
	cin >> native_place;
	int i = 1;
	while (stu[i].getName() != "Andy") {
		i++;
	}
	stu[i].setStudent(name, i, sex, date, address, native_place);
	cout << "录入学生信息成功!" << endl;
}

int search_by_number(Student *stu, const int num)
{
	int n = 1;
	while (stu[n].getName() != "Andy") {
		++n;
	}
	if (num > n - 1)
		return 0;
	int i = 1;
	while (i < n) {
		if (i == num)
			return i;
		i++;
	}
	return 0;
}

void search_by_name(Student *stu, const string name)
{
	int n = 1;
	while (stu[n].getName() != "Andy") {
		n++;
	}
	int i = 1;
	int flag = 0;
	while (i++ < n) {
		if (stu[i].getName() == name) {
			stu[i].printStudent();
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "找不到此学生信息!" << endl;
}

void modify_student(Student *stu, int num, int choice)
{
	//choice:1.性别\t2.出生日期\t3.地址\t4.籍贯  
	switch (choice) {
	case 1:
	{
		cout << "输入性别:";
		string sex1;
		cin >> sex1;
		stu[num].setSex(sex1);
		break;
	}
	case 2:
	{
		Date date;
		try {
			cout << "输入出生日期:";
			cin >> date;
		}
		catch (Date_Exception &e) {
			cout << e.getSide() << e.what() << endl;
			cout << "是否要重新输入(y or n)";
			char ch;
			cin >> ch;
			if (ch == 'y') {
				cout << "出生日期:";
				cin >> date;
			}
			else {
				cout << "修改信息失败!" << endl;
				return;
			}
		}
		stu[num].setDate(date);
		break;
	}

	case 3:
	{
		cout << "输入地址:";
		string address;
		cin >> address;
		stu[num].setAddress(address);
		break;
	}
	case 4:
	{
		cout << "输入籍贯:";
		string native_place;
		cin >> native_place;
		stu[num].setNativePlace(native_place);
		break;
	}

	}
	cout << "修改信息成功!" << endl;
}

void delete_student(Student *stu, int num)
{
	Date date(0, 0, 0);
	stu[num].setStudent("无", 0, "无", date, "无", "无");
	cout << "删除信息成功!" << endl;
}

void write_file(Student *stu, const string file_name)
{
	//格式("Andy", 1, "男", date, "西安", "江苏")  
	ofstream output;
	output.open(file_name);
	if (output.fail()) {
		cout << "can't open the file" << endl;
	}
	int n = 1;
	while (stu[n].getName() != "Andy") {
		n++;
	}
	for (int i = 1; i < n; i++) {
		if (stu[i].getName() == "无") {
			output << endl;
			continue;
		}
		output << setw(5) << stu[i].getName() << setw(8) << stu[i].getNumber() << setw(13) << stu[i].getSex() << setw(17)
			<< stu[i].getDate() << setw(24) << stu[i].getAddress() << setw(29) << stu[i].getNativePlace() << endl;
	}
	output.close();
	cout << "数据写入文件成功!" << endl;
}
