#include "Student.h"  
#include "interface.h"  
#include <iostream>  
#include <cstdlib>  
#include <iomanip>  
#include <fstream>  

using namespace std;
const int MAX = 200;//�����С   

void menu_display();//��ʾ�˵�  
void print_students_info(Student *stu);//��ʾȫ��ѧ����Ϣ  
void read_student_info(Student *stu);//¼��ѧ����Ϣ  
int search_by_number(Student *stu, const int num);//����ѧ�Ų�ѯ  
void search_by_name(Student *stu, const string name);//����������ѯ ��������  
void modify_student(Student *stu, int num, int choice);//�޸�ѧ����Ϣ  
void delete_student(Student *stu, int num);//ɾ��ѧ����Ϣ  
void write_file(Student *stu, const string file_name);//���浽�ļ�  

int main()
{
	Front();//��ʼ�Ľ���   

	Date date[4];
	date[1].setDate(1996, 2, 3);
	date[2].setDate(1995, 12, 1);
	date[3].setDate(1997, 6, 6);
	Student students[MAX];
	students[1].setStudent("��һ", 1, "��", date[1], "����", "����");
	students[2].setStudent("����", 2, "Ů", date[2], "����", "����");
	students[3].setStudent("����", 3, "��", date[3], "����", "�㽭");

	int flag = 1;
	while (flag) {
		menu_display();
		cout << "��������ִ�еĲ���:";
		int ch;
		cin >> ch;
		switch (ch) {
		case 1:
		{			
			cout << endl;
			cout << "��ʾ��ǰȫ��ѧ����Ϣ:" << endl;
			print_students_info(students);
			cout << endl;
			break;
		}

		case 2:
		{
			cout << endl;
			cout << "��������¼���ѧ����Ϣ:(ѧ�Ÿ��ݵ�ǰѧ�������Զ�����)" << endl;
			read_student_info(students);
			cout << "��ʾ��ǰȫ��ѧ����Ϣ:" << endl;
			print_students_info(students);
			cout << endl;
			break;
		}	

		case 3:
		{
			cout << endl;
			cout << "1.����ѧ�Ų�ѯ\t2.����������ѯ\t3.�˳�:";
			int choice;
			cin >> choice;
			if (choice == 1) {
				cout << "��������ҵ�ѧ��:";
				int num;
				cin >> num;
				int i = search_by_number(students, num);
				if (i == 0)
					cout << "�Ҳ�����ѧ����Ϣ" << endl << endl;
				else {
					cout << "ѧ����Ϣ����:" << endl;
					students[i].printStudent();
					cout << endl;
				}
			}
			else if (choice == 2) {
				cout << "��������ҵ�����:";
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
			cout << "�����������޸ĵ�ѧ��:";
			int i;
			cin >> i;
			int n = 1;
			while (students[n].getName() != "Andy") {
				n++;
			}//�����ڵ�ѧ������  
			if (i > n - 1) {
				cout << "û�д�ѧ����Ϣ!" << endl;
				cout << endl;
			}
			else {
				cout << "���������޸ĵ�����(1.�Ա�\t2.��������\t3.��ַ\t4.����):";
				int no;
				cin >> no;
				modify_student(students, i, no);
				cout << "��ʾ��ǰȫ��ѧ����Ϣ:" << endl;
				print_students_info(students);
				cout << endl;
			}
			break;
		}

		case 5:
		{
			cout << endl;
			cout << "����������ɾ����ѧ��:";
			int i0;
			cin >> i0;
			delete_student(students, i0);
			cout << "��ʾ��ǰȫ��ѧ����Ϣ:" << endl;
			print_students_info(students);
			cout << endl;
			break;
		}

			
		case 6:
		{
			cout << endl;
			cout << "��������д����ļ���:";
			string file_name;
			cin >> file_name;
			write_file(students, file_name);
			cout << endl;
			break;
		}

		case 7:
		{
			cout << endl;
			cout << "�˳�ϵͳ!";
			cout << endl;
			flag = 0;
			break;
		}

		}//switch  
	}//while  
	cout << endl;

	Back();//��������   
	return 0;
}

void menu_display()
{
	for (int i = 0; i<10; i++)
		cout << "*";
	cout << "ѧ������ϵͳ";
	for (int i = 0; i<10; i++)
		cout << "*";
	cout << endl;
	cout << "* 1.��ʾ" << "\t\t" << "2.¼�� *" << endl;
	cout << "* 3.��ѯ" << "\t\t" << "4.�޸� *" << endl;
	cout << "* 5.ɾ��" << "\t\t" << "6.��ӡ *" << endl;
	cout << "* 7.�˳�" << "\t\t" << "       *" << endl;
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
	cout << "����" << "   " << "ѧ��" << "  " << "�Ա�" << setw(12) << "��������" << setw(12) << "��ַ" << setw(12) << "����" << endl;
	for (int i = 1; i < num; i++) {
		if (stu[i].getName() == "��") {
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
	cout << "����:";
	cin >> name;
	cout << "�Ա�:";
	cin >> sex;
	try {
		cout << "��������:";
		cin >> date;
	}
	catch (Date_Exception &e) {
		cout << e.getSide() << e.what() << endl;
		cout << "�Ƿ�Ҫ��������(y or n)";
		//char ch;
		int ch;
		cin >> ch;
		if (ch == 'y') {
			cout << "��������:";
			cin >> date;
		}
		else {
			cout << "¼����Ϣʧ��!" << endl;
			return;
		}
	}
	cout << "��ַ:";
	cin >> address;
	cout << "����:";
	cin >> native_place;
	int i = 1;
	while (stu[i].getName() != "Andy") {
		i++;
	}
	stu[i].setStudent(name, i, sex, date, address, native_place);
	cout << "¼��ѧ����Ϣ�ɹ�!" << endl;
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
		cout << "�Ҳ�����ѧ����Ϣ!" << endl;
}

void modify_student(Student *stu, int num, int choice)
{
	//choice:1.�Ա�\t2.��������\t3.��ַ\t4.����  
	switch (choice) {
	case 1:
	{
		cout << "�����Ա�:";
		string sex1;
		cin >> sex1;
		stu[num].setSex(sex1);
		break;
	}
	case 2:
	{
		Date date;
		try {
			cout << "�����������:";
			cin >> date;
		}
		catch (Date_Exception &e) {
			cout << e.getSide() << e.what() << endl;
			cout << "�Ƿ�Ҫ��������(y or n)";
			char ch;
			cin >> ch;
			if (ch == 'y') {
				cout << "��������:";
				cin >> date;
			}
			else {
				cout << "�޸���Ϣʧ��!" << endl;
				return;
			}
		}
		stu[num].setDate(date);
		break;
	}

	case 3:
	{
		cout << "�����ַ:";
		string address;
		cin >> address;
		stu[num].setAddress(address);
		break;
	}
	case 4:
	{
		cout << "���뼮��:";
		string native_place;
		cin >> native_place;
		stu[num].setNativePlace(native_place);
		break;
	}

	}
	cout << "�޸���Ϣ�ɹ�!" << endl;
}

void delete_student(Student *stu, int num)
{
	Date date(0, 0, 0);
	stu[num].setStudent("��", 0, "��", date, "��", "��");
	cout << "ɾ����Ϣ�ɹ�!" << endl;
}

void write_file(Student *stu, const string file_name)
{
	//��ʽ("Andy", 1, "��", date, "����", "����")  
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
		if (stu[i].getName() == "��") {
			output << endl;
			continue;
		}
		output << setw(5) << stu[i].getName() << setw(8) << stu[i].getNumber() << setw(13) << stu[i].getSex() << setw(17)
			<< stu[i].getDate() << setw(24) << stu[i].getAddress() << setw(29) << stu[i].getNativePlace() << endl;
	}
	output.close();
	cout << "����д���ļ��ɹ�!" << endl;
}
