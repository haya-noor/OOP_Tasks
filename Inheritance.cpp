#include<iostream>
#include<string>
using namespace std;

class vehicle
{
protected:
    int no_of_tires;
    string size;
    int no_of_seats;

public:
    vehicle(int t, string s, int st)
    {
        no_of_tires = t;
        size = s;
        no_of_seats = st;
    }

    void set_value(int t, string s, int st)
    {
        no_of_tires = t;
        size = s;
        no_of_seats = st;
    }

    void get_value()
    {
        cout << "Number of tires: " << no_of_tires << endl;
        cout << "Size: " << size << endl;
        cout << "Number of seats: " << no_of_seats << endl;
    }

    virtual void print() = 0;

    ~vehicle(){}
};


class car : public vehicle
{
protected:
    string color;

public:
    car(int t, string s, int st, string c) : vehicle(t, s, st)
    {
        color = c;
    }

    void set_value(int t, string s, int st, string c)
    {
        vehicle::set_value(t, s, st);
        color = c;
    }

    void get_value()
    {
        vehicle::get_value();
        cout << "Color: " << color << endl;
    }

    virtual void print()
    {
        cout << "Number of tires: " << no_of_tires << endl;
        cout << "Size: " << size << endl;
        cout << "Number of seats: " << no_of_seats << endl;
        cout << "Color: " << color << endl;
    }

    ~car(){}
};

class vitz : public car
{
private:
    string model;
    int plate_num;

public:
    vitz(int t, string s, int st, string c, string m, int p) : car(t, s, st, c)
    {
        model = m;
        plate_num = p;
    }

    void set_value(int t, string s, int st, string c, string m, int p)
    {
        car::set_value(t, s, st, c);
        model = m;
        plate_num = p;
    }

    void get_value()
    {
        car::get_value();
        cout << "Model: " << model << endl;
        cout << "Plate number: " << plate_num << endl;
    }

    virtual void print()
    {
        car::print();
        cout << "Model number: " << model << endl;
        cout << "Plate number: " << plate_num << endl;
    }

    ~vitz(){}
};

int main()
{
    vitz v(4, "Medium", 2, "dragon orange", "Valkyrie", 404);
    cout << "Initial values:\n";
    v.print();
    cout << endl;

    v.set_value(4, "Medium", 1, "Blue", "2024", 500);
    cout << "Updated values:\n";
    v.print();

    return 0;
}
