#include<iostream>
#include <string>
#include"snack.h"
#include"SnackSlot.h"
#include"VendingMachine.h"

using namespace std;

int main()
{   
	setlocale(LC_ALL, "RUS");

	int money = 10000;
	int slotcnt = 4;
	int slotsize = 5;
	
	VendingMachine* machine = new VendingMachine(slotcnt, slotsize);

	printf("\t �� ������� �������� ������� �� %d ������\n", slotcnt);
	printf("\t ������ ���� �������� �������� � %d �����\n", slotsize);
	printf("\t ��������� �������� ������ ���������� (�� �����) ��������� � ���������� ���\n\n");

	machine->autofill();
	machine->showSlots();

	printf("\n\t ������ ���� �������� %d\n" , machine->getSlotSize(1));
	printf("\t ���������� � ��� ���� %d �����\n\n", money);

	machine->buySnackfromslot(1, money);

	printf("\t �� ������ 1 ������� �� ������� ����� \n");
	printf("\t ����� �������� %d\n", money);
	printf("\t � ������ ����� �������� %d �������\n\n", machine->getSlotSize(1));

	machine->buySnackfromslot(1, money, 2);

	printf("\t �� ������ 2 ������� �� ������� ����� \n");
	printf("\t ����� �������� %d\n", money);
	printf("\t � ������ ����� �������� %d �������\n\n", machine->getSlotSize(1));

	machine->buySnackfromslot(1, money, 3);

	printf("\t �� ����������� ������ 3 ������� �� ������� �����, �� ��� ���� ������ %d\n", machine->getSlotSize(1));

	machine->slotAtofill(1);

	printf("\n\t �� ��������� ���� ������ ���������, ������ ��� %d �������\n", machine->getSlotSize(1));
	printf("\n\t ����������� ������ ����\n");

	machine->printSlot(1);

	printf("\n\t ����������� �����\n\n");

	machine->showSlots();

	printf("\n\t ��������� ����� ��� ������ ����� ������ ���� N1\n");

	machine->deleteSlot(1);

	printf("\t ������ � ����� ������ %d �������� ������ �� %d ���������\n", machine->getFullnes(), machine->getMachineSize());
	printf("\t ���������� �������� ����� \n\n");

	machine->showSlots();
	
    Snack sn{"SuperSnikers", "SuperPuper", 56.7, 300, 1200};

	printf("\n\t �� ������� ���� ��������\n");
	cout << sn << endl;

	printf("\t ������� �������� � ���� ������ � ���������� �� �����������\n");

    machine->addSlot(sn);
	machine->showSlots();

	printf("\n\n");

	return 0;
}