#include <iostream>
#include <chrono>
#include <thread>  
using namespace std;

class Kawiarka
{
public:
    void setter() {
        turn_on();
        start_get_water();
        stop_get_water();
        get_coffee();
        start_heat_water();
        stop_heat_water();
        rush_coffee();
        spill_out_water();
        turn_off();
        information();
    }

private:
    int water_temperature;
    bool cup = false, state_water = false, state_machine = false, water_heat = false;

    void turn_on() {
        state_machine = true;
        cout << "Maszyna jest zalaczona" << endl;
    }

    void check_cup() {
        cup = true;
        cout << "Kubek jest umieszczony" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    void start_get_water() {
        state_water = true;
        water_temperature = 5;
        cout << "Woda zaczela sie wlewac" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    void stop_get_water() {
        state_water = false;
        cout << "Woda osiagnela odpowiedni poziom" << endl;
    }

    void get_coffee() {
        cout << "Kawa zostala zmielona i przygotowana do wsypania do kubka" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    void start_heat_water() {
        water_heat = true;
        cout << "Woda zaczela sie podgrzewac" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }

    void stop_heat_water() {
        water_heat = false;
        water_temperature = 100;
        cout << "Woda osiagnela poziom wrzenia" << endl;
    }

    void spill_out_water() {
        cout << "Kubek zostal zalany wrzaca woda" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    void rush_coffee() {
        cout << "Kawa zostala wsypana do kubka" << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    void information() {
        cout << "Kawa została przygotowana, dziekuje za zakup." << endl;
    }

    void turn_off() {
        cout << "Maszyna jest wyłaczona" << endl;
        state_machine = false;
    }
};

int main()
{
    Kawiarka Automat_kawowy;
    Automat_kawowy.setter();

    return 0;
}
