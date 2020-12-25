#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
private:

protected:
	int wheels;
	int weight;
public:
	Vehicle(int wh, int we) :wheels(wh), weight(we){}
	void SetWheels(int wh) { wheels = wh; }
	void SetWeight(int we) { weight = we; }
	int GetWheels() const { return wheels; }
	int GetWeight() const { return weight; }
	void show() const;
};
void Vehicle::show() const
{
	cout << "汽车车轮个数：" << wheels << endl;
	cout << "汽车重量：" << weight << endl;
}
class Car :private Vehicle
{
protected:
	int passengerLoad;
public:
	Car(int pl, int wh, int we) :Vehicle(wh, we), passengerLoad(pl) {}
	void SetPassengerLoad(int pl) { passengerLoad = pl; }
	int GetPassengerLoad() const { return passengerLoad; }
	void show() const;
};
void Car::show() const
{
	cout << "轿车"<<endl;
	cout << "汽车车轮个数：" << wheels << endl;
	cout << "载人数：" << passengerLoad << endl;
	cout << "汽车重量：" << weight << "kg" << endl;
}
class Truck :private Vehicle
{
protected:
	int passengerLoad;
	int payload;
public:
	Truck(int p, int pd, int wh, int we) :Vehicle(wh, we), passengerLoad(p), payload(pd) {}
	void SetPassenger(int p) { passengerLoad = p; }
	void SetPayLoad(int pd) { payload = pd; }
	int GetPassenger() const { return passengerLoad; }
	int GetPayLoad() const { return payload; }
	void show() const;
};
void Truck::show()const
{
	cout << "货车"<<endl;
	cout << "汽车车轮个数：" << wheels << endl;
	cout << "载人数：" << passengerLoad << endl;
	cout << "载重量：" << payload << "kg" << endl;
	cout << "汽车重量：" << weight << "kg" << endl;
}
int main()
{
	Car car1(4, 5, 2000);
	car1.show();
	Truck truck1(2, 80000, 8, 3000);
	truck1.show();
	return 0;
}