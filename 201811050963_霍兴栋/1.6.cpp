#include<iostream>
#include <math.h>
using namespace std;
// 汽车类vehicle
class vehicle
{
protected:
         int wheels;
         int weight;
public:
         vehicle(int wh, int we);
         void display_data();
};
//传递参数的构造函数
vehicle::vehicle(int wh, int we)
{
         wheels = wh;
         weight = we;
}

void vehicle::display_data()
{
        cout << "wheels=" << wheels << endl;
        cout << "weight=" << weight << endl;
}
//私有派生类小车类car
class car:private vehicle
{
   int passenger_load;
public:
    car(int wh, int we, int pa);
    void display_data();
};

car::car(int wh, int we, int pa) :vehicle(wh,we)
{
    passenger_load = pa;
}
void car::display_data()
{

    vehicle::display_data();
    cout << "passenger_load=" << passenger_load << endl;
}
//vehicle的私有派生类车类truck
class truck :private vehicle
{
     int passenger_load;
     int payload;
public:
     truck(int wh, int we, int pa,int pay);
     void display_data();
};

truck::truck(int wh, int we, int pa,int pay) :vehicle(wh, we)
  {
     passenger_load = pa;
     payload = pay;
   }
void truck::display_data()
{   
     vehicle::display_data();
     cout << "passenger_load=" << passenger_load<<endl;
     cout<< "payload=" << payload << endl;
}

int main()
{
     cout<<"The message of vehicle:"<<endl;
     vehicle veh(4, 1000);
     veh.display_data();
     cout<<"The message of car:"<<endl;
     car ca(4, 1000, 4);
     ca.display_data();
      cout<<"The message of truck:"<<endl;
     truck tru(8, 5000, 2, 30000);
     tru.display_data();

    system("pause");
    return 0;
}






