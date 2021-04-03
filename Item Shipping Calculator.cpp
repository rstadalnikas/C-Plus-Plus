#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    //variables
    string itemName;
    string fragile;
    float itemTotal;
    string destination;
    float shippingCost = 0;

    //Program header
    cout << "..................................................\n"
         << "ITCS 2530 - Programming Assignment for week #3\n"
         << "..................................................\n\n" << endl;

    //Information inputs
    cout << "Please enter the item name (no spaces)...........:";
    cin >> itemName;

    cout << "Is the item fragile (y=yes/n=no).................:";
    cin >> fragile;

    cout << "Please enter your order total....................:";
    cin >> itemTotal;

    cout << "Please enter destination. (usa/can/aus/mars)..........:";
    cin >> destination;

    //convert destination string to lowercase
    transform(destination.begin(), destination.end(), destination.begin(), ::tolower);
    
    //algorithm to determine shipping cost
    if (itemTotal <= 150 && itemTotal >= 100.01) { //item cost 100.01-150.00
        if (destination == "usa"){
            shippingCost = 12;
        }
        else{
            if (destination == "can"){
                shippingCost = 15;
            }
            else{
                if (destination == "aus"){
                    shippingCost = 17;
                }
                else{
                    shippingCost = 2400;
                }
            }
        }
    }
    if (itemTotal <= 100 && itemTotal >= 50.01) { //item cost 50.01-100.00
        if (destination == "usa"){
            shippingCost = 9;
        }
        else{
            if (destination == "can"){
                shippingCost = 12;
            }
            else{
                if (destination == "aus"){
                    shippingCost = 14;
                }
                else{
                    shippingCost = 2200;
                }
            }
        }
    }
    if (itemTotal <= 50) { //item cost <= 50
        if (destination == "usa"){
            shippingCost = 6;
        }
        else {
            if (destination == "can"){
                shippingCost = 8;
            }
            else{
                if (destination == "aus"){
                    shippingCost = 10;
                }
                else{
                    shippingCost = 2000;
                }
            }
        }
    }

    if (fragile == "y" || fragile == "Y"){
       shippingCost += 2;
    }

    //convert destination string to uppercase
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

    //converts float values to strings with decimal precision set
    stringstream aa;
    aa << setprecision(2) << fixed << (itemTotal + shippingCost);
    string totalCost = aa.str();

    stringstream bb;
    bb << setprecision(2) << fixed << shippingCost;
    string costShipping = bb.str();

    

    //output information to screen
    string receipt = "\nYour item is............................" + itemName +
        "\nYour shipping cost is...................$" + costShipping +
        "\nYou are shipping to....................." + destination +
        "\nYour total shipping costs are...........$" + totalCost +
        "\n\n----------------------------------------Thank You!\n";

    //create, open, and save to file
    ofstream outfile;
    outfile.open("Order.txt");
    outfile << receipt << endl;

    //output to console
    cout << receipt << endl;

    system("pause");

    return 0;

}