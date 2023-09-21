#include "SnackSlot.h"

SnackSlot::SnackSlot() = default;

SnackSlot::SnackSlot(int size)
{
	slotSize = size;
	slot = new Snack[size];
}

SnackSlot::~SnackSlot()
{
	delete[] slot;
}

bool SnackSlot::addSnack(Snack snackName)
{
	
	if(slotFullnes < slotSize)
	{
		if(snackName.getName() == slot[0].getName())
		{

			slot[slotFullnes] = snackName;

			slotFullnes++;

			return true;
		}
		else
			return false;
	}
	else
		return false;
}

void SnackSlot::printSlot()
{
	cout << endl;
	for(int i = 0; i < slotFullnes; i++)
        cout << slot[i] << endl;
}

int SnackSlot::getSlotFullnes()
{
	return slotFullnes;
}

int SnackSlot::getSlotSize()
{
	return slotSize;
}

bool SnackSlot::getSnack(Snack& sn)
{
	if (slotFullnes)
	{
		sn = slot[0];

		for (int i = 0; i < (slotFullnes - 1); i++)
			slot[i] = slot[i + 1];

		slotFullnes--;

		return 1;
	}
	else
        return 0;
}

void SnackSlot::randomFill()
{
	Snack sn;
	string s;

	sn.randomFill();
	s = sn.getName();

	slot[0] = sn;

	for (int i = 1; i < slotSize; i++)
	{
		sn.randomParamsForName(s);
		slot[i] = sn;
	}

	slotFullnes = slotSize;
}

bool SnackSlot::getHeader(string& str)
{
	if (slotFullnes)
	{
		str = slot[0].getName();
		return 1;
	}
	else
		return 0;

}

bool SnackSlot::getPrice(int& price)
{
	if (slotFullnes)
	{
		price = slot[0].getPrice();
		return 1;
	}
	else
		return 0;

}
void SnackSlot::addFullSlot(Snack snackName)
{
	for(int i = 0; i < slotSize; i++)
		slot[i] = snackName;

	slotFullnes = slotSize;
}

SnackSlot& SnackSlot::operator=(SnackSlot& other)
{
	for (int i = 0; i < slotSize ; i++)
		slot[i] = other.slot[i];

	return *this;
}