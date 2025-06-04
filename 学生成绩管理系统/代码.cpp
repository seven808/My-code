#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
const int studentNum = 4;//这里可以更改学生的人数
struct student {
	int num;//学号
	string name;//姓名
	int foxscore;//fox成绩
	int cscore;//C成绩
	int englishscore;//英语成绩
	int total;
};
student students[studentNum];
//信息输入
void input() {
	for (int i = 0; i < studentNum; i++)
	{
		cout << "请输入第" << i + 1 << "个学生的信息" << endl;
		cout << "学号:";
		cin >> students[i].num;
		cout << endl << "姓名:";
		cin >> students[i].name;
		cout <<endl<< "fox成绩:";
		cin >> students[i].foxscore;
		cout << endl << "c成绩:";
		cin >> students[i].cscore;
		cout << endl << "英语成绩:";
		cin >> students[i].englishscore;
	}
}
//总分统计
void count() {
	for (int i = 0; i < studentNum; i++)
	{
		students[i].total=students[i].cscore+ students[i].foxscore+ students[i].englishscore;
		cout << students[i].name << "的总分为：" << students[i].total << endl;
	}
}
//总分排序
void sort() {
	//比较总分，先整理顺序
	for (int i = 0; i < studentNum; i++)
	{
		for (int j = i + 1; j < studentNum; j++)
		{
			if (students[i].total < students[j].total)
				swap(students[i], students[j]);//交换位置，实现排序
		}
	}
	//输出排序表
	cout << left << setw(8) << "学号" 
		<< setw(8) << "姓名" 
		<< setw(8) << "fox成绩" 
		<< setw(8) << "C成绩" 
		<< setw(8) << "英语成绩" 
		<< setw(8) << "总分" 
		<< endl;
	for (int i = 0; i < studentNum; i++)
	{
		cout << left << setw(8) << students[i].num
			<< setw(8) << students[i].name
			<< setw(8) << students[i].foxscore
			<< setw(8) << students[i].cscore
			<< setw(8) << students[i].foxscore
			<< setw(8) << students[i].total
			<< endl;
	}
}
//查询
void query() {
	int id;
	cout << "请输入你要查询的学生的学号：";
	cin >> id;
	bool found = false;
	for (int i = 0; i < studentNum; i++) {
		if (id == students[i].num)
		{
			cout << left << setw(8) << "学号"
				<< setw(8) << "姓名"
				<< setw(8) << "fox成绩"
				<< setw(8) << "C成绩"
				<< setw(8) << "英语成绩"
				<< setw(8) << "总分"
				<< endl;
			cout << left << setw(8) << students[i].num
				<< setw(8) << students[i].name
				<< setw(8) << students[i].foxscore
				<< setw(8) << students[i].cscore
				<< setw(8) << students[i].foxscore
				<< setw(8) << students[i].total
				<< endl;
			found = true;
			break;
		}
	}
	if (found == false) {
		cout << "学号有误，未能查找到该学生";
	}
}
//主程序，菜单页面
int main() {
	int choice;
	do {
		cout << "====学生成绩管理====" << endl
			<< "(1)信息输入" << endl
			<< "(2)总分统计" << endl
			<< "(3)总分排序" << endl
			<< "(4)查询" << endl
			<< "(0)退出程序" << endl;
		cout << "请输入你的选择：";
		cin >> choice;
		switch (choice) {
		case 1:
			input();
			break;
		case 2:
			count();
			break;
		case 3:
			sort();
			break;
		case 4:
			query();
			break;
		case 0:
			cout << "已退出";
			break;
		default:
			cout << "无效选项，重新输入";
			break;
		}
	} while (choice != 0);
	return 0;
}
