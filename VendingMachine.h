#ifndef VENDINGMACHUNE
#define VENDINGMACHUNE

#include"SnackSlot.h"

class VendingMachine
{
public:
	VendingMachine();
	VendingMachine(int slotCnt, int slotSize);
	~VendingMachine();
	void printSlot(int slotNum);        // �������� ���������� ����� 
    void showSlots();                   // �������� ��������� �������� ������ � ���� ������ � ���
	void autofill();                    // �������������� ���� ������
	void slotAtofill(int slotNum);      // �������������� �����
	bool addSlot(Snack snack);          // ��������� ������ ���� ������ ..
	int getSlotSize(int slotNum);       // ���������� ������ �����
	int getFullnes();                   // ���������� ���������� �������� ������ ������
	int getMachineSize();               // ���������� ����������� ��������� ���������� ������ ��� ������ ������
	bool buySnackfromslot(int slotNum, int& money, int snackCnt = 1); // ������ �� ����� ������� �� ������ (1 �� ���������)
	bool deleteSlot(int slotNum);       // ������� ���� �� ������� slotNum � �������� ��������� �����
	SnackSlot** getPtr();               // ���������� ��������� �� �����
private:

	SnackSlot** slots = nullptr;
	int crrSlots = 0;               // ���������� ������������ ������ 
	int slotsCnt;                   // ������ ������
};

#endif // VENDINGMACHUNE