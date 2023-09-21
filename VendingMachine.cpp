#include "VendingMachine.h"

VendingMachine::VendingMachine() = default;


VendingMachine::VendingMachine(int slotCnt, int slotSize)
{
	slotsCnt = slotCnt;
	slots = new SnackSlot * [slotCnt];
	for (int i = 0; i < slotCnt; i++)
		slots[i] = new SnackSlot(slotSize);
}

VendingMachine::~VendingMachine()
{
	for (int i = 0; i < slotsCnt; i++)
		delete[] slots[i];

	delete[] slots;
}

void VendingMachine::printSlot(int slotNum)
{
	slots[slotNum]->printSlot();
}

void VendingMachine::showSlots()
{
	if(crrSlots)
	{
		string str;
		int price;

		for (int i = 0; i < crrSlots; i++)
		{
			if (slots[i]->getHeader(str) && slots[i]->getPrice(price))
				cout << "� " << i << " ����� ����� " << str << " �� ���� " << price << " �� �����" << endl;
			else
				cout << "�� ������� �������� �������� ���� ��� ������������� ������" << endl;
		}
	}
	else
		cout << "��� ��������� ������ " << endl;
}

void VendingMachine::autofill()
{
	crrSlots = slotsCnt;
	for (int i = 0; i < slotsCnt; i++)
		slots[i]->randomFill();
}

void VendingMachine::slotAtofill(int slotNum)
{
	slots[slotNum]->randomFill();
}

int VendingMachine::getSlotSize(int slotNum)
{
	return slots[slotNum]->getSlotFullnes();
}

int VendingMachine::getFullnes()
{
	return crrSlots;
}

bool VendingMachine::deleteSlot(int slotNum)
{
	if(slotNum < slotsCnt)
	{	
		if(slotNum <= (crrSlots - 1))
		{
			for (int i = slotNum; i < crrSlots - 1; i++)
				*(slots[i]) = *(slots[i + 1]);

			crrSlots--;

			return true;
		}
		else
			return false;
	}
	else
		return false;
}

bool VendingMachine::buySnackfromslot(int slotNum, int& money, int snackCnt)
{
	int price;
	Snack sn;

	if (slots[slotNum]->getPrice(price))
	{
		if (slotNum >= crrSlots)
			return false;
		else
		{
			if (money >= price )
			{
				if (snackCnt < slots[slotNum]->getSlotFullnes())
				{
					price *= snackCnt;
					money -= price;

					for (int i = 0; i < snackCnt; i++)
					{
						slots[slotNum]->getSnack(sn);
						cout << "machine: �� ������ " << sn.getName() << " �� " << price << " �����" << endl;
					}
				}
				else
                    cout << "machine: �������� ������ � �����" << endl;
			}
			else
				cout << "machine: ������������ �����" << endl;
		}
	}
	else
		return false;
}

bool VendingMachine::addSlot(Snack snack)
{
	if(crrSlots < slotsCnt)
	{
		slots[crrSlots]->addFullSlot(snack);
		crrSlots++;

		return true;
	}
	else
		return false;
}


int VendingMachine::getMachineSize()
{
	return slotsCnt;
}

SnackSlot** VendingMachine::getPtr()
{
	return slots;
}
