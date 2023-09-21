#ifndef VENDINGMACHUNE
#define VENDINGMACHUNE

#include"SnackSlot.h"

class VendingMachine
{
public:
	VendingMachine();
	VendingMachine(int slotCnt, int slotSize);
	~VendingMachine();
	void printSlot(int slotNum);        // печатает содержимое слота 
    void showSlots();                   // печатает заголовки активных слотов и цену товара в них
	void autofill();                    // автозаполнение всей машины
	void slotAtofill(int slotNum);      // автозаполнение слота
	bool addSlot(Snack snack);          // добавляет полный слот снеков ..
	int getSlotSize(int slotNum);       // возвращает размер слота
	int getFullnes();                   // возвращяет количество активных слотов машины
	int getMachineSize();               // возвращает максимально возможное количество слотов для данной машины
	bool buySnackfromslot(int slotNum, int& money, int snackCnt = 1); // купить из слота сколько то снеков (1 по умолчанию)
	bool deleteSlot(int slotNum);       // удаляет слот по индексу slotNum и сдвигает остальные слоты
	SnackSlot** getPtr();               // возвращяет указатель на слоты
private:

	SnackSlot** slots = nullptr;
	int crrSlots = 0;               // количетсво используемых слотов 
	int slotsCnt;                   // размер машины
};

#endif // VENDINGMACHUNE