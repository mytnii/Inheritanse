#include<iostream>
using namespace std;

#define delimiter cout << "\n--------------------------------------------------------\n"

class Vehicle
{
public:
	virtual void move() = 0; // ����� ����������� �����
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
		cout << "�� ������� �������������� � ������� ���� ������\n";
		cout << "������������� �� ����� � ������� ����� ������� ���������� �����\n";
	}
};

class Airplane : public AirVehicle, GroundVehicle, WaterVehicle
{
public:
	void move()
	{
		cout << "�� ������� ������������� � ������� ������������ ��������� � �������\n";
		cout << "�� ����� ������������� ��� ������ ����� � ������������ ���������\n";
		cout << "�� ���� ������������� ��� ������ ������������ ���������\n";
	}
};

class Boat : WaterVehicle
{
public:
	void move()
	{
		cout << "������������� �� ���� ��� ������ ��������� � �������� �����\n";
	}
};

class Yacht : WaterVehicle
{
public:
	void move()
	{
		cout << "������������� �� ���� � �������  ����� � ������\n";
	}
};

class Car : GroundVehicle
{
public:
	void move()
	{
		cout << "������ ���� �� 4-� �������" << endl;
	}
};

class Bike :GroundVehicle
{
public:
	void move()
	{
		cout << "�������� ���� �� 2 - � �������" << endl;
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