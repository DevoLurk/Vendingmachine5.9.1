#ifndef SNACKSLOT
#define SNACKSLOT

#include"Snack.h"

class SnackSlot
{
public:
	SnackSlot();
	SnackSlot(int Size);               
	~SnackSlot();                      
	void printSlot();                  // печатает слот
	bool getHeader(string& str);       // возвращет название слота (название первого снека если он есть) .. принято что в слоте все снеки одинаковые
	bool getPrice(int& price);         // возвращает цену снеков в слоте (цену первого если он есть) .. принято что в слоте все снеки одинаковые
	bool addSnack(Snack snackName);    // добавляет снек если есть место в слоте
	void addFullSlot(Snack snackName); // добавляет полный слот снеков
	bool getSnack(Snack& sn);          // достает снек если он есть
	int getSlotFullnes();              // возвращает количество снеков в слоте
	int getSlotSize();                 // возвращает размер слота
	void randomFill();                 // заполнение случайными снеками
	SnackSlot& operator=(SnackSlot& other);
private:
	Snack* slot = nullptr;             // Указатель на слот
	int slotFullnes = 0;               // заполнение слота
	int slotSize;                      // размер слота
};

#endif // SNACKSLOT
