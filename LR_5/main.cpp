#include <iostream>
#include <vector>

using namespace std;

// Электроприборы
class IElectricDevice
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void charge() = 0;
    virtual bool isCharged() const = 0;
    virtual double getPower() const = 0;
    virtual ~IElectricDevice() {}
};

// Светящихся предметы
class ILightDevice
{
public:
    virtual void lightOn() = 0;
    virtual void lightOff() = 0;
    virtual bool isLighting() const = 0;
    virtual ~ILightDevice() {}
};

// Фильтр
class Filter
{
private:
    bool check = true;
    double current_power = 0;
    double max_power;
    vector<IElectricDevice*> devices;

public:
    Filter(double max_p) : max_power(max_p) {}

    bool addDevice(IElectricDevice* device) {
        devices.push_back(device);
        return true;
    }

    void chargeAll() {
        if (!check) {
            cout << "Фильтр в защите! Нужно сбросить защиту." << endl;
            return;
        }

        current_power = 0;
        for (auto device : devices) {
            device->charge();
            current_power += device->getPower();
            
            if (current_power > max_power) {
                cout << "The protection worked!" << endl;
                check = false;
                break;
            }
        }
    }

    void reset() {
        check = true;
        current_power = 0;
        cout << "Protection is reset!" << endl;
    }

    double getCurrentPower() const {
        return current_power;
    }
};

// Гирлянда
class Girlanda
{
private:
    vector<ILightDevice*> light_devices;

public:
    void addLightDevice(ILightDevice* device) {
        light_devices.push_back(device);
    }

    void turnOnAll() {
        for (auto device : light_devices) {
            device->lightOn();
        }
    }

    void turnOffAll() {
        for (auto device : light_devices) {
            device->lightOff();
        }
    }
};

// Реализация электроприборов

// Лампочка
class Lamp : public IElectricDevice, public ILightDevice
{
private:
    bool status = false;
    bool charged = false;
    double power = 60.0;

public:
    void turnOn() override {
        status = true;
    }

    void turnOff() override {
        status = false;
    }

    void charge() override {
        charged = true;
    }

    bool isCharged() const override {
        return charged;
    }

    double getPower() const override {
        return power;
    }

    void lightOn() override {
        if (charged && status) {
            cout << "Lamp is turned on!" << endl;
        } else {
            cout << "Lamp isn`t worked by: " 
                 << (charged ? "turned off" : "not charget") << endl;
        }
    }

    void lightOff() override {
        cout << "Lamp turned off!" << endl;
    }

    bool isLighting() const override {
        return charged && status;
    }
};

// Электроутюг
class Iron : public IElectricDevice
{
private:
    bool status = false;
    bool charged = false;
    double power = 1500.0;

public:
    void turnOn() override {
        status = true;
        cout << "Iron turned on!" << endl;
    }

    void turnOff() override {
        status = false;
        cout << "Iron turned off!" << endl;
    }

    void charge() override {
        charged = true;
    }

    bool isCharged() const override {
        return charged;
    }

    double getPower() const override {
        return power;
    }
};

// Фонарик (электроприбор + светящийся предмет)
class Flashlight : public IElectricDevice, public ILightDevice
{
private:
    bool status = false;
    bool charged = false;
    double power = 5.0;

public:
    void turnOn() override {
        status = true;
    }

    void turnOff() override {
        status = false;
    }

    void charge() override {
        charged = true;
    }

    bool isCharged() const override {
        return charged;
    }

    double getPower() const override {
        return power;
    }

    void lightOn() override {
        if (charged && status) {
            cout << "Flashlight is turned on!" << endl;
        } else {
            cout << "Flashlight isn`t worked by: " 
                 << (charged ? "turned off" : "not charged") << endl;
        }
    }

    void lightOff() override {
        cout << "Flashlight isn`t turned off!" << endl;
    }

    bool isLighting() const override {
        return charged && status;
    }
};

// Светящиеся предметы, не требующие электричества

// Керосиновая лампа
class Kerosene_lamp : public ILightDevice
{
private:
    bool is_on = false;
    bool has_fuel = false;

public:
    void addFuel() {
        has_fuel = true;
        cout << "В керосиновую лампу залили топливо." << endl;
    }

    void lightOn() override {
        if (has_fuel) {
            is_on = true;
            cout << "Керосиновая лампа светится!" << endl;
        } else {
            cout << "В керосиновой лампе нет топлива!" << endl;
        }
    }

    void lightOff() override {
        is_on = false;
        cout << "Керосиновая лампа погашена." << endl;
    }

    bool isLighting() const override {
        return is_on && has_fuel;
    }
};

// Свечка
class Candle : public ILightDevice
{
private:
    bool is_on = false;

public:
    void lightOn() override {
        is_on = true;
        cout << "Свечка зажжена и светится!" << endl;
    }

    void lightOff() override {
        is_on = false;
        cout << "Свечка погашена." << endl;
    }

    bool isLighting() const override {
        return is_on;
    }
};







int main()
{
    // Создание объектов
    Lamp lamp;
    Iron iron;
    Flashlight flashlight;
    Kerosene_lamp kerosene;
    Candle candle;

    // Создание сетевого фильтра с ограничением мощности
    Filter filter(1000.0);
    
    // Добавляем электроприборы в фильтр
    filter.addDevice(&lamp);
    filter.addDevice(&flashlight);
    // filter.addDevice(&iron); // Если добавить утюг, то фильтр выпадет в защиту
    
    // Заряжаем все приборы в фильтре
    filter.chargeAll();
    
    // Включаем приборы
    lamp.turnOn();
    flashlight.turnOn();
    
    // Создаем гирлянду
    Girlanda girlanda;
    
    // Добавляем светящиеся предметы в гирлянду
    girlanda.addLightDevice(&lamp);
    girlanda.addLightDevice(&flashlight);
    girlanda.addLightDevice(&kerosene);
    girlanda.addLightDevice(&candle);
    
    // Подготавливаем неэлектрические светящиеся предметы
    kerosene.addFuel();
    
    // Включаем все светящиеся предметы в гирлянде
    girlanda.turnOnAll();
    
    // Выключаем все светящиеся предметы в гирлянде
    girlanda.turnOffAll();
    
    return 0;
}