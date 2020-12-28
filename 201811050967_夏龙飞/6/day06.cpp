#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
private:

protected:
	string name;
	int wheels;
	int weight;
public:
	Vehicle(int wh, int we, string nm) :wheels(wh), weight(we) { name = nm; }
	void SetWheels(int wh) { wheels = wh; }
	void SetWeight(int we) { weight = we; }
	void SetName(char nm[]) { name = nm; }
	int GetWheels() const { return wheels; }
	int GetWeight() const { return weight; }
	string GetName() const { return name; }
	void show() const;
};
void Vehicle::show() const
{
	cout << "�������" << name << endl;
	cout << "�������ָ�����" << wheels << endl;
	cout << "����������" << weight << endl;
}
class Car :private Vehicle
{
protected:
	int passengerLoad;
public:
	Car(int pl, int wh, int we, string nm) :Vehicle(wh, we, nm), passengerLoad(pl) {}
	void SetPassengerLoad(int pl) { passengerLoad = pl; }
	int GetPassengerLoad() const { return passengerLoad; }
	void show() const;
};
void Car::show() const
{
	cout << "�������" << name << endl;
	cout << "�������ָ�����" << wheels << endl;
	cout << "��������" << passengerLoad << endl;
	cout << "����������" << weight << "kg" << endl;
}
class Truck :private Vehicle
{
protected:
	int passengerLoad;
	int payload;
public:
	Truck(int p, int pd, int wh, int we, string nm) :Vehicle(wh, we, nm), passengerLoad(p), payload(pd) {}
	void SetPassenger(int p) { passengerLoad = p; }
	void SetPayLoad(int pd) { payload = pd; }
	int GetPassenger() const { return passengerLoad; }
	int GetPayLoad() const { return payload; }
	void show() const;
};
void Truck::show()const
{
	cout << "�������" << name << endl;
	cout << "�������ָ�����" << wheels << endl;
	cout << "��������" << passengerLoad << endl;
	cout << "��������" << payload << "��" << endl;
	cout << "����������" << weight << "��" << endl;
}
int main()
{
	Car car1(4, 4, 1400, "С����");
	car1.show();
	Truck truck1(4, 2, 8, 3, "����");
	truck1.show();

	system("PAUSE");
	return 0;
}
