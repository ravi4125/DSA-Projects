#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ============================================================
//  UTILITY: Console colors & formatting
// ============================================================
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define WHITE "\033[37m"
#define BG_BLUE "\033[44m"

void printLine(char ch = '-', int len = 60)
{
    cout << string(len, ch) << endl;
}

void printHeader(const string &title)
{
    cout << endl;
    cout << BOLD << CYAN;
    printLine('=');
    cout << "  " << title << endl;
    printLine('=');
    cout << RESET;
}

// ============================================================
//  BASE CLASS: Vehicle
// ============================================================
class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

protected:
    static int totalVehicles;

public:
    // Default Constructor
    Vehicle() : vehicleID(0), manufacturer("Unknown"), model("Unknown"), year(2000)
    {
        totalVehicles++;
    }

    // Parameterized Constructor
    Vehicle(int id, const string &mfr, const string &mdl, int yr)
        : vehicleID(id), manufacturer(mfr), model(mdl), year(yr)
    {
        totalVehicles++;
    }

    // Copy Constructor
    Vehicle(const Vehicle &v)
        : vehicleID(v.vehicleID), manufacturer(v.manufacturer),
          model(v.model), year(v.year)
    {
        totalVehicles++;
    }

    // Destructor
    virtual ~Vehicle()
    {
        totalVehicles--;
    }

    // --- Getters ---
    int getVehicleID() const { return vehicleID; }
    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    int getYear() const { return year; }

    // --- Setters ---
    void setVehicleID(int id) { vehicleID = id; }
    void setManufacturer(const string &m) { manufacturer = m; }
    void setModel(const string &m) { model = m; }
    void setYear(int y) { year = y; }

    // Static getter
    static int getTotalVehicles() { return totalVehicles; }

    // Virtual display (overridden in derived classes)
    virtual void display() const
    {
        cout << BOLD << GREEN << "  [Vehicle]" << RESET << endl;
        cout << "  ID          : " << YELLOW << vehicleID << RESET << endl;
        cout << "  Manufacturer: " << manufacturer << endl;
        cout << "  Model       : " << model << endl;
        cout << "  Year        : " << year << endl;
    }

    virtual string getType() const { return "Vehicle"; }
};

int Vehicle::totalVehicles = 0;

// ============================================================
//  SINGLE INHERITANCE: Car  <-- Vehicle
// ============================================================
class Car : public Vehicle
{
private:
    string fuelType; // Petrol / Diesel / CNG / Hybrid

public:
    Car() : Vehicle(), fuelType("Petrol") {}

    Car(int id, const string &mfr, const string &mdl, int yr, const string &fuel)
        : Vehicle(id, mfr, mdl, yr), fuelType(fuel) {}

    ~Car() override {}

    // Getter / Setter
    string getFuelType() const { return fuelType; }
    void setFuelType(const string &f) { fuelType = f; }

    void display() const override
    {
        Vehicle::display();
        cout << BOLD << GREEN << "  [Car]" << RESET << endl;
        cout << "  Fuel Type   : " << fuelType << endl;
    }

    string getType() const override { return "Car"; }
};

// ============================================================
//  MULTILEVEL INHERITANCE: ElectricCar  <-- Car  <-- Vehicle
// ============================================================
class ElectricCar : public Car
{
private:
    double batteryCapacity; // kWh

public:
    ElectricCar() : Car(), batteryCapacity(0.0) {}

    ElectricCar(int id, const string &mfr, const string &mdl, int yr, double bat)
        : Car(id, mfr, mdl, yr, "Electric"), batteryCapacity(bat) {}

    ~ElectricCar() override {}

    double getBatteryCapacity() const { return batteryCapacity; }
    void setBatteryCapacity(double cap) { batteryCapacity = cap; }

    void display() const override
    {
        Car::display();
        cout << BOLD << GREEN << "  [ElectricCar]" << RESET << endl;
        cout << "  Battery     : " << batteryCapacity << " kWh" << endl;
    }

    string getType() const override { return "ElectricCar"; }
};

// ============================================================
//  BASE CLASS FOR MULTIPLE INHERITANCE: Aircraft
// ============================================================
class Aircraft
{
private:
    double flightRange; // km

public:
    Aircraft() : flightRange(0.0) {}
    explicit Aircraft(double fr) : flightRange(fr) {}
    virtual ~Aircraft() {}

    double getFlightRange() const { return flightRange; }
    void setFlightRange(double fr) { flightRange = fr; }

    virtual void displayAircraft() const
    {
        cout << BOLD << GREEN << "  [Aircraft]" << RESET << endl;
        cout << "  Flight Range: " << flightRange << " km" << endl;
    }
};

// ============================================================
//  MULTIPLE INHERITANCE: FlyingCar  <-- Car, Aircraft
// ============================================================
class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar() : Car(), Aircraft() {}

    FlyingCar(int id, const string &mfr, const string &mdl, int yr,
              const string &fuel, double fr)
        : Car(id, mfr, mdl, yr, fuel), Aircraft(fr) {}

    ~FlyingCar() override {}

    void display() const override
    {
        Car::display();
        displayAircraft();
        cout << BOLD << GREEN << "  [FlyingCar]" << RESET << endl;
    }

    string getType() const override { return "FlyingCar"; }
};

// ============================================================
//  MULTILEVEL INHERITANCE: SportsCar  <-- ElectricCar  <-- Car  <-- Vehicle
// ============================================================
class SportsCar : public ElectricCar
{
private:
    double topSpeed; // km/h

public:
    SportsCar() : ElectricCar(), topSpeed(0.0) {}

    SportsCar(int id, const string &mfr, const string &mdl, int yr,
              double bat, double ts)
        : ElectricCar(id, mfr, mdl, yr, bat), topSpeed(ts) {}

    ~SportsCar() override {}

    double getTopSpeed() const { return topSpeed; }
    void setTopSpeed(double ts) { topSpeed = ts; }

    void display() const override
    {
        ElectricCar::display();
        cout << BOLD << GREEN << "  [SportsCar]" << RESET << endl;
        cout << "  Top Speed   : " << topSpeed << " km/h" << endl;
    }

    string getType() const override { return "SportsCar"; }
};

// ============================================================
//  HIERARCHICAL INHERITANCE: Sedan  <-- Car  <-- Vehicle
// ============================================================
class Sedan : public Car
{
private:
    int numDoors;

public:
    Sedan() : Car(), numDoors(4) {}

    Sedan(int id, const string &mfr, const string &mdl, int yr,
          const string &fuel, int doors = 4)
        : Car(id, mfr, mdl, yr, fuel), numDoors(doors) {}

    ~Sedan() override {}

    int getNumDoors() const { return numDoors; }
    void setNumDoors(int d) { numDoors = d; }

    void display() const override
    {
        Car::display();
        cout << BOLD << GREEN << "  [Sedan]" << RESET << endl;
        cout << "  Doors       : " << numDoors << endl;
    }

    string getType() const override { return "Sedan"; }
};

// ============================================================
//  HIERARCHICAL INHERITANCE: SUV  <-- Car  <-- Vehicle
// ============================================================
class SUV : public Car
{
private:
    bool hasFourWD;

public:
    SUV() : Car(), hasFourWD(false) {}

    SUV(int id, const string &mfr, const string &mdl, int yr,
        const string &fuel, bool fourWD = true)
        : Car(id, mfr, mdl, yr, fuel), hasFourWD(fourWD) {}

    ~SUV() override {}

    bool getHasFourWD() const { return hasFourWD; }
    void setHasFourWD(bool f) { hasFourWD = f; }

    void display() const override
    {
        Car::display();
        cout << BOLD << GREEN << "  [SUV]" << RESET << endl;
        cout << "  4WD         : " << (hasFourWD ? "Yes" : "No") << endl;
    }

    string getType() const override { return "SUV"; }
};

// ============================================================
//  VEHICLE REGISTRY CLASS  (Array of Vehicle* pointers)
// ============================================================
class VehicleRegistry
{
private:
    static const int MAX_VEHICLES = 100;
    Vehicle *vehicles[MAX_VEHICLES];
    int count;

public:
    VehicleRegistry() : count(0)
    {
        for (int i = 0; i < MAX_VEHICLES; i++)
            vehicles[i] = nullptr;
    }

    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete vehicles[i];
            vehicles[i] = nullptr;
        }
    }

    bool addVehicle(Vehicle *v)
    {
        if (count >= MAX_VEHICLES)
        {
            cout << RED << "  Registry is full!" << RESET << endl;
            return false;
        }
        vehicles[count++] = v;
        cout << GREEN << "  Vehicle added successfully! (Total: "
             << Vehicle::getTotalVehicles() << ")" << RESET << endl;
        return true;
    }

    void displayAll() const
    {
        if (count == 0)
        {
            cout << YELLOW << "  No vehicles registered yet." << RESET << endl;
            return;
        }
        for (int i = 0; i < count; i++)
        {
            cout << BOLD << BLUE;
            printLine('-');
            cout << "  #" << (i + 1) << "  Type: " << vehicles[i]->getType() << RESET << endl;
            printLine('-');
            vehicles[i]->display();
        }
    }

    void searchByID(int id) const
    {
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << BOLD << BLUE;
                printLine('-');
                cout << "  Found! Type: " << vehicles[i]->getType() << RESET << endl;
                printLine('-');
                vehicles[i]->display();
                found = true;
                break;
            }
        }
        if (!found)
            cout << RED << "  No vehicle found with ID: " << id << RESET << endl;
    }

    int getCount() const { return count; }
};

// ============================================================
//  HELPER: Input helpers
// ============================================================
int readInt(const string &prompt)
{
    int x;
    cout << prompt;
    cin >> x;
    cin.ignore();
    return x;
}
double readDouble(const string &prompt)
{
    double x;
    cout << prompt;
    cin >> x;
    cin.ignore();
    return x;
}
string readString(const string &prompt)
{
    string s;
    cout << prompt;
    getline(cin, s);
    return s;
}
bool readBool(const string &prompt)
{
    char c;
    cout << prompt << " (y/n): ";
    cin >> c;
    cin.ignore();
    return (c == 'y' || c == 'Y');
}

// ============================================================
//  VEHICLE ADDITION MENU
// ============================================================
Vehicle *createVehicle()
{
    cout << endl
         << BOLD << CYAN << "  Select Vehicle Type:" << RESET << endl;
    cout << "  1. Car (Single Inheritance)" << endl;
    cout << "  2. Electric Car (Multilevel: Car->ElectricCar)" << endl;
    cout << "  3. Flying Car (Multiple: Car + Aircraft)" << endl;
    cout << "  4. Sports Car (Multilevel: Car->ElectricCar->SportsCar)" << endl;
    cout << "  5. Sedan (Hierarchical from Car)" << endl;
    cout << "  6. SUV (Hierarchical from Car)" << endl;
    int choice = readInt("  Choice: ");

    int id = readInt("  Vehicle ID      : ");
    string mfr = readString("  Manufacturer    : ");
    string mdl = readString("  Model           : ");
    int yr = readInt("  Year            : ");

    switch (choice)
    {
    case 1:
    {
        string fuel = readString("  Fuel Type       : ");
        return new Car(id, mfr, mdl, yr, fuel);
    }
    case 2:
    {
        double bat = readDouble("  Battery (kWh)   : ");
        return new ElectricCar(id, mfr, mdl, yr, bat);
    }
    case 3:
    {
        string fuel = readString("  Fuel Type       : ");
        double fr = readDouble("  Flight Range(km): ");
        return new FlyingCar(id, mfr, mdl, yr, fuel, fr);
    }
    case 4:
    {
        double bat = readDouble("  Battery (kWh)   : ");
        double ts = readDouble("  Top Speed(km/h) : ");
        return new SportsCar(id, mfr, mdl, yr, bat, ts);
    }
    case 5:
    {
        string fuel = readString("  Fuel Type       : ");
        int doors = readInt("  Number of Doors : ");
        return new Sedan(id, mfr, mdl, yr, fuel, doors);
    }
    case 6:
    {
        string fuel = readString("  Fuel Type       : ");
        bool fourWD = readBool("  4WD");
        return new SUV(id, mfr, mdl, yr, fuel, fourWD);
    }
    default:
        cout << RED << "  Invalid choice. Creating generic Car." << RESET << endl;
        return new Car(id, mfr, mdl, yr, "Petrol");
    }
}

// ============================================================
//  MAIN – Menu-Driven
// ============================================================
int main()
{
    VehicleRegistry registry;

    // Pre-load sample vehicles
    registry.addVehicle(new Car(101, "Toyota", "Corolla", 2022, "Petrol"));
    registry.addVehicle(new ElectricCar(102, "Tesla", "Model 3", 2023, 75.0));
    registry.addVehicle(new FlyingCar(103, "AeroMobil", "4.0", 2023, "Hybrid", 750.0));
    registry.addVehicle(new SportsCar(104, "Rimac", "Nevera", 2023, 120.0, 412.0));
    registry.addVehicle(new Sedan(105, "Honda", "Accord", 2021, "Petrol", 4));
    registry.addVehicle(new SUV(106, "Ford", "Everest", 2022, "Diesel", true));

    int choice;
    do
    {
        printHeader("  VEHICLE REGISTRY SYSTEM");
        cout << BOLD;
        cout << "  1.  Add Vehicle" << endl;
        cout << "  2.  View All Vehicles" << endl;
        cout << "  3.  Search by ID" << endl;
        cout << "  4.  Show Total Vehicles" << endl;
        cout << "  0.  Exit" << endl;
        cout << RESET;
        printLine();
        choice = readInt("  Enter your choice: ");

        switch (choice)
        {
        case 1:
        {
            printHeader("ADD VEHICLE");
            Vehicle *v = createVehicle();
            if (v)
                registry.addVehicle(v);
            break;
        }
        case 2:
        {
            printHeader("ALL REGISTERED VEHICLES");
            registry.displayAll();
            break;
        }
        case 3:
        {
            printHeader("SEARCH BY ID");
            int id = readInt("  Enter Vehicle ID: ");
            registry.searchByID(id);
            break;
        }
        case 4:
        {
            printHeader("STATISTICS");
            cout << "  Total Vehicles Registered : "
                 << YELLOW << BOLD << Vehicle::getTotalVehicles() << RESET << endl;
            break;
        }
        case 0:
            printHeader("GOODBYE");
            cout << GREEN << "  Exiting Vehicle Registry System. Goodbye!" << RESET << endl;
            break;
        default:
            cout << RED << "  Invalid option. Please try again." << RESET << endl;
        }

        if (choice != 0)
        {
            cout << endl
                 << CYAN << "  Press ENTER to continue...";
            cin.get();
        }

    } while (choice != 0);

    return 0;
}