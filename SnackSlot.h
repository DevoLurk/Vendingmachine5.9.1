#ifndef SNACKSLOT
#define SNACKSLOT

#include"Snack.h"

class SnackSlot
{
public:
	SnackSlot();
	SnackSlot(int Size);               
	~SnackSlot();                      
	void printSlot();                  // �������� ����
	bool getHeader(string& str);       // ��������� �������� ����� (�������� ������� ����� ���� �� ����) .. ������� ��� � ����� ��� ����� ����������
	bool getPrice(int& price);         // ���������� ���� ������ � ����� (���� ������� ���� �� ����) .. ������� ��� � ����� ��� ����� ����������
	bool addSnack(Snack snackName);    // ��������� ���� ���� ���� ����� � �����
	void addFullSlot(Snack snackName); // ��������� ������ ���� ������
	bool getSnack(Snack& sn);          // ������� ���� ���� �� ����
	int getSlotFullnes();              // ���������� ���������� ������ � �����
	int getSlotSize();                 // ���������� ������ �����
	void randomFill();                 // ���������� ���������� �������
	SnackSlot& operator=(SnackSlot& other);
private:
	Snack* slot = nullptr;             // ��������� �� ����
	int slotFullnes = 0;               // ���������� �����
	int slotSize;                      // ������ �����
};

#endif // SNACKSLOT
