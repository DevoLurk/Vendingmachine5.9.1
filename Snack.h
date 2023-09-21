#ifndef SNACK
#define SNACK

#include<string>
#include<iostream>
#include<random>

using namespace std;

class Snack
{
public:
	Snack();
	Snack(string name, string mnfcturer, float weight, int clrie, int price);
	string getName();
	int getPrice();
	void randomFill();
	void randomParamsForName(string name);
	friend ostream& operator << (ostream& output, const Snack& s);
	Snack operator=(Snack sn);

private:
	int random(int min, int max);
    string names[8] = {"������", "�������", "���������", "�������", "������", "��������", "�������", "�������"};
	string mnfcrurers[5] = {"������", "��������", "������", "����������", "����������"};

	string name;             // �������� �������
	string mnfcturer;        // �������������
	float weight;            // ���
	int clrie;               // �������������
	int price;               // ����	
}; 

#endif // SNACK