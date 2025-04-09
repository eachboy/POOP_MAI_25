#include <iostream>

using namespace std;

class Car
{
    private:
        string _model = "Toyota Camry"; //модель 
        double _engine_capacity = 3.5f; //объем двигателя
        double _max_fuel = 50.0f; //макс топлива
        double _fuel_consumption = 0.1f; //расход топлива
        double _сurrent_fuel_consumption = 10.0f; //текущее топливо
        double _mileage = 0.1f; //пробег

    public:
        void drive(double distance)
        {
            if (_сurrent_fuel_consumption - _fuel_consumption < 0) {
                cout << "No fuel to drive" << endl;
            };

            _сurrent_fuel_consumption -=  _fuel_consumption * distance;
            _mileage += distance;
        };

        void refuel(double add_fuel)
        {
            if (_сurrent_fuel_consumption < _max_fuel)
            {
                _сurrent_fuel_consumption += add_fuel;
            };

            if (_сurrent_fuel_consumption > _max_fuel) 
            {
                _сurrent_fuel_consumption = _max_fuel;
            }
        };

        void data()
        {
            cout << "Model: " << _model << endl;
            cout << "Engine_capacity: " << _engine_capacity << endl;
            cout << "Full fuel: " << _max_fuel << endl;
            cout << "Current fuel: " << _сurrent_fuel_consumption << endl;
            cout << "Мileage: " << _mileage << endl;
            printf("\n\n\n");
        };
};

int main()
{
    Car car;
    car.data();
    car.drive(10);
    car.data();
    car.refuel(20);
    car.data();

    return 0;
}