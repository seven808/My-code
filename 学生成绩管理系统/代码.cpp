#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
const int studentNum = 4;//������Ը���ѧ��������
struct student {
	int num;//ѧ��
	string name;//����
	int foxscore;//fox�ɼ�
	int cscore;//C�ɼ�
	int englishscore;//Ӣ��ɼ�
	int total;
};
student students[studentNum];
//��Ϣ����
void input() {
	for (int i = 0; i < studentNum; i++)
	{
		cout << "�������" << i + 1 << "��ѧ������Ϣ" << endl;
		cout << "ѧ��:";
		cin >> students[i].num;
		cout << endl << "����:";
		cin >> students[i].name;
		cout <<endl<< "fox�ɼ�:";
		cin >> students[i].foxscore;
		cout << endl << "c�ɼ�:";
		cin >> students[i].cscore;
		cout << endl << "Ӣ��ɼ�:";
		cin >> students[i].englishscore;
	}
}
//�ܷ�ͳ��
void count() {
	for (int i = 0; i < studentNum; i++)
	{
		students[i].total=students[i].cscore+ students[i].foxscore+ students[i].englishscore;
		cout << students[i].name << "���ܷ�Ϊ��" << students[i].total << endl;
	}
}
//�ܷ�����
void sort() {
	//�Ƚ��ܷ֣�������˳��
	for (int i = 0; i < studentNum; i++)
	{
		for (int j = i + 1; j < studentNum; j++)
		{
			if (students[i].total < students[j].total)
				swap(students[i], students[j]);//����λ�ã�ʵ������
		}
	}
	//��������
	cout << left << setw(8) << "ѧ��" 
		<< setw(8) << "����" 
		<< setw(8) << "fox�ɼ�" 
		<< setw(8) << "C�ɼ�" 
		<< setw(8) << "Ӣ��ɼ�" 
		<< setw(8) << "�ܷ�" 
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
//��ѯ
void query() {
	int id;
	cout << "��������Ҫ��ѯ��ѧ����ѧ�ţ�";
	cin >> id;
	bool found = false;
	for (int i = 0; i < studentNum; i++) {
		if (id == students[i].num)
		{
			cout << left << setw(8) << "ѧ��"
				<< setw(8) << "����"
				<< setw(8) << "fox�ɼ�"
				<< setw(8) << "C�ɼ�"
				<< setw(8) << "Ӣ��ɼ�"
				<< setw(8) << "�ܷ�"
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
		cout << "ѧ������δ�ܲ��ҵ���ѧ��";
	}
}
//�����򣬲˵�ҳ��
int main() {
	int choice;
	do {
		cout << "====ѧ���ɼ�����====" << endl
			<< "(1)��Ϣ����" << endl
			<< "(2)�ܷ�ͳ��" << endl
			<< "(3)�ܷ�����" << endl
			<< "(4)��ѯ" << endl
			<< "(0)�˳�����" << endl;
		cout << "���������ѡ��";
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
			cout << "���˳�";
			break;
		default:
			cout << "��Чѡ���������";
			break;
		}
	} while (choice != 0);
	return 0;
}
