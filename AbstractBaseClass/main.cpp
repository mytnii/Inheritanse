#include<iostream>
using namespace std;

#define delimiter cout << "\n--------------------------------------------------------\n"

class Vehicle
{
public:
	virtual void move() = 0; // Чисто виртуальный метод
};

class GroundVehicle : public Vehicle
{

};

class WaterVehicle :public Vehicle
{

};

class AirVehicle : public Vehicle
{

};

class Helicopter :public AirVehicle, GroundVehicle
{

public:
	void move()
	{
		cout << "По воздуху передвтигается с помощью двух винтов\n";
		cout << "Передвигается по земле с помощью шасси наклона подъемного винта\n";
	}
};

class Airplane : public AirVehicle, GroundVehicle, WaterVehicle
{
public:
	void move()
	{
		cout << "По воздуху передвигается с помощью авиационного двигателя и крыльев\n";
		cout << "По земле передвигается при помощи шасси и авиационного двигателя\n";
		cout << "По воде передвигается при помощи авиационного двигателя\n";
	}
};

class Boat : WaterVehicle
{
public:
	void move()
	{
		cout << "Передвигается по воде при помоши двигателя и гребного винта\n";
	}
};

class Yacht : WaterVehicle
{
public:
	void move()
	{
		cout << "Передвигается по воде с помощью  ветра и паруса\n";
	}
};

class Car : GroundVehicle
{
public:
	void move()
	{
		cout << "Машина едет на 4-х колесах" << endl;
	}
};

class Bike :GroundVehicle
{
public:
	void move()
	{
		cout << "Мотоцикл едит на 2 - х колесах" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	delimiter;
	Helicopter helicopter;
	helicopter.move();
	delimiter;

	Airplane airplane;
	airplane.move();
	delimiter;

	Boat boat;
	boat.move();
	delimiter;

	Yacht yacht;
	yacht.move();
	delimiter;

	Car car;
	car.move();
	delimiter;

	Bike bike;
	bike.move();
	delimiter;

}