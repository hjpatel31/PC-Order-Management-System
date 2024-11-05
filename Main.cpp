#include <iostream>
#include <iomanip>

using namespace std;

class PC 
{
private:
    double cpuSpeed; // Speed of the CPU in GHz
    int hdCapacity;  // Capacity of the hard disk in GB
    int ramCapacity; // Capacity of RAM in GB
    double cost;     // Cost of the PC

public:
    // Default constructor
    PC() : cpuSpeed(2.2), hdCapacity(500), ramCapacity(8) 
    {
        calculateCost();
    }

    // Constructor with three parameters
    PC(double speed, int hd, int ram) : cpuSpeed(speed), hdCapacity(hd), ramCapacity(ram) 
    {
        calculateCost();
    }

    // Function to obtain PC data from the user
    void getData() 
    {
        cout << endl << "Please enter the speed of CPU(GHz): ";
        cin >> cpuSpeed;

        cout << "Pleas enter the size hard disk(GB): ";
        cin >> hdCapacity;

        cout << "Please enter the size of RAM(GB): ";
        cin >> ramCapacity;

        calculateCost();
    }

    // Function to compute and return the cost of the PC
    double calculateCost() 
    {
        cost = 500 + cpuSpeed * 100 + hdCapacity * 0.05 + ramCapacity * 10;
        return cost;
    }

    // Function to display PC data
    void displayData() const 
    {
        cout << cpuSpeed << " GHz" " CPU Speed,  " << hdCapacity << " GB" " HD,  " << ramCapacity << " GB" " RAM,  " " $" << cost << endl;
        cout << endl;
    }
};

int main() 
{
    cout << "\t\t*******************************************************************************" << endl;
    cout << "\t\t***This lab assignment is submitted by Heli Patel with student ID 143017226 ***" << endl;
    cout << "\t\t*******************************************************************************" << endl;

    int numPCs;

    cout << endl << "How many PCs you want to order: ";
    cin >> numPCs;

    // Dynamic array of PC objects
    PC* pcs = new PC[numPCs];

    // Obtain PC data from the user for each PC
    for (int i = 0; i < numPCs; ++i) 
    {
        cout << endl << "Enter data for PC " << i + 1 << ":" << std::endl;
        pcs[i].getData();
    }

    // Display PC data for each PC
    cout << "\nPC Data:" << endl ;
    for (int i = 0; i < numPCs; ++i) 
    {
        cout << endl <<"PC " << i + 1 << ":\n";
        pcs[i].displayData();
    }

    // Compute and display total cost of all PCs ordered
    double totalCost = 0;
    for (int i = 0; i < numPCs; ++i) 
    {
        totalCost += pcs[i].calculateCost();
    }
    cout << "Total Cost of All PCs: $" << totalCost << endl;

    // Deallocate the dynamic array
    delete[] pcs;

    return 0;
}
