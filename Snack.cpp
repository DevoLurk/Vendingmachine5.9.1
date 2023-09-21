#include"Snack.h"	

using namespace std;

Snack::Snack() = default;

Snack::Snack(string name, string mnfcturer, float weight, int clrie, int price)
{
	this->name = name;
	this->mnfcturer = mnfcturer;
	this->weight = weight;
	this->clrie = clrie;
	this->price = price;
}
string Snack::getName()
{
	return name;
}

int Snack::getPrice()
{
	return price;
}

void Snack::randomFill()
{
	name = names[random(0, 7)];                  // выбор из 8
	mnfcturer = mnfcrurers[random(0, 4)];        // выбор из 5
	weight = ((float)random(200, 1400) / 10);    // от 20.0 до 140.0
	clrie = random(200, 480);                    // от 200 до 480
	price = random(50, 300);                     // от 50 до 300
}

int Snack::random(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);

	return dist(gen);
}

void Snack::randomParamsForName(string name)
{
	this->name = name;
	mnfcturer = mnfcrurers[random(0, 4)];        // выбор из 5
	weight = ((float)random(200, 1400) / 10);    // от 20.0 до 140.0
	clrie = random(200, 480);                    // от 200 до 480
	price = random(50, 300);                     // от 50 до 300
}



ostream& operator<<(ostream& output, const Snack& s)
{
	output << "Название закуски:        " << s.name << endl
		   << "Производитель:           " << s.mnfcturer << endl
		   << "Вес в граммах:           " << s.weight << endl
		   << "Каллорийность:           " << s.clrie << endl
	       << "Цена :                   " << s.price << endl;
	return output;
}

Snack Snack::operator=(Snack sn)
{
	name = sn.name;
	mnfcturer = sn.mnfcturer;
	weight = sn.weight;
	clrie = sn.clrie;
	price = sn.price;

	return *this;
}