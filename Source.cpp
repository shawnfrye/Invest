#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Declare variables 
    float initialInvestment, monthlyDeposit, annualInterest, months, years;
    //Declare variables to store year end amounts
    float totalAmount, interestAmount, yearEndInterest;


    //Display form 
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of years: \n";

    //Wait for input 
    system("PAUSE");

    //Get data from user
    cout << "********************************\n";
    cout << "********** Data Input **********\n";
    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;
    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;
    cout << "Annual Interest: %";
    cin >> annualInterest;
    cout << "Number of years: ";
    cin >> years;
    months = years * 12;

    //Wait for input from user
    system("PAUSE");

    //Set total amount to initial investment to be updated
    totalAmount = initialInvestment;

    //Display year data without monthly deposits
    cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";


    for (int i = 0; i < years; i++) {

        //Calculate year interest
        interestAmount = (totalAmount) * ((annualInterest / 100));

        //Calculate year end amount
        totalAmount = totalAmount + interestAmount;

        //Print results to table 
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << "\n";

    }

    //Set total amount to initial investment 
    totalAmount = initialInvestment;

    //Display year data with monthly deposits
    cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
    cout << "==============================================================\n";
    cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
    cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < years; i++) {

        //Set yearly interest to zero at the start of the year
        yearEndInterest = 0;

        for (int j = 0; j < 12; j++) {

            //Calculate monthly interest
            interestAmount = (totalAmount + monthlyDeposit) * ((annualInterest / 100) / 12);

            //Calculate month end interest
            yearEndInterest = yearEndInterest + interestAmount;

            //Calculate month end total
            totalAmount = totalAmount + monthlyDeposit + interestAmount;

        }

        //Print results to table showcasing only two decimal points
        cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearEndInterest << "\n";


    }

    return 0;
}