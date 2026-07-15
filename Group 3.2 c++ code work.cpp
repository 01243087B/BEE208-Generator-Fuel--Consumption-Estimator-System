#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//==============================
// Generator Class
//==============================
class Generator
{
private:
    string generatorID;
    double rating;
    double runningHours;
    double fuelRate;
    double fuelPrice;
    double fuelConsumed;
    double fuelCost;
    string usageStatus;

public:

    // Function to accept input
    void inputData()
    {
        cout << "\nEnter generator ID: ";
        cin >> generatorID;

        // Input Validation
        do
        {
            cout << "Enter generator rating in kVA: ";
            cin >> rating;

            if (rating <= 0)
                cout << "Invalid input! Rating must be greater than zero.\n";

        } while (rating <= 0);

        do
        {
            cout << "Enter running hours: ";
            cin >> runningHours;

            if (runningHours <= 0)
                cout << "Invalid input! Running hours must be greater than zero.\n";

        } while (runningHours <= 0);

        do
        {
            cout << "Enter fuel consumption rate in litres per hour: ";
            cin >> fuelRate;

            if (fuelRate <= 0)
                cout << "Invalid input! Fuel rate must be greater than zero.\n";

        } while (fuelRate <= 0);

        do
        {
            cout << "Enter fuel price per litre: ";
            cin >> fuelPrice;

            if (fuelPrice <= 0)
                cout << "Invalid input! Fuel price must be greater than zero.\n";

        } while (fuelPrice <= 0);
    }

    // Function to calculate fuel consumed and cost
    void calculate()
    {
        fuelConsumed = fuelRate * runningHours;
        fuelCost = fuelConsumed * fuelPrice;

        if (fuelConsumed <= 10)
        {
            usageStatus = "Low Fuel Usage";
        }
        else if (fuelConsumed <= 30)
        {
            usageStatus = "Moderate Fuel Usage";
        }
        else
        {
            usageStatus = "High Fuel Usage";
        }
    }

    // Function to display report
    void display()
    {
        cout << fixed << setprecision(2);

        cout << "\nFuel Consumed: "
             << fuelConsumed << " litres";

        cout << "\nEstimated Fuel Cost: GHS "
             << fuelCost;

        cout << "\nUsage Status: "
             << usageStatus << endl;
    }

    // Function to save report into file
    void saveToFile(ofstream &file)
    {
        file << fixed << setprecision(2);

        file << "Generator ID: " << generatorID << endl;
        file << "Generator Rating: " << rating << " kVA" << endl;
        file << "Running Hours: " << runningHours << endl;
        file << "Fuel Consumption Rate: " << fuelRate << " L/hr" << endl;
        file << "Fuel Price: GHS " << fuelPrice << endl;
        file << "Fuel Consumed: " << fuelConsumed << " litres" << endl;
        file << "Estimated Fuel Cost: GHS " << fuelCost << endl;
        file << "Usage Status: " << usageStatus << endl;
        file << "----------------------------------------" << endl;
    }
};

//==============================
// Main Function
//==============================
int main()
{
    vector<Generator> generators;

    int records;

    cout << "=============================================\n";
    cout << " GENERATOR FUEL CONSUMPTION ESTIMATOR SYSTEM\n";
    cout << "=============================================\n";

    do
    {
        cout << "\nEnter number of generator records: ";
        cin >> records;

        if (records <= 0)
        {
            cout << "Invalid input! Number of records must be greater than zero.\n";
        }

    } while (records <= 0);

    // Open output file
    ofstream report("generator_fuel_report.txt");

    report << "GENERATOR FUEL CONSUMPTION ESTIMATOR SYSTEM\n";
    report << "=========================================\n\n";

    // Loop through records
    for (int i = 0; i < records; i++)
    {
        Generator gen;

        cout << "\nRecord " << i + 1 << endl;

        gen.inputData();

        gen.calculate();

        gen.display();

        gen.saveToFile(report);

        generators.push_back(gen);
    }

    report.close();

    cout << "\nReport saved successfully to generator_fuel_report.txt\n";

    return 0;
}