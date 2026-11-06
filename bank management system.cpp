
#include <iostream>
using namespace std;

int main()
{
    int accountNumber[10];
    string accountName[10];
    float balance[10];

    int totalAccounts = 0;
    int choice, accNo;
    float amount;
    int found;

    do
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Check Balance\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                if (totalAccounts < 10)
                {
                    cout << "\nEnter Account Number: ";
                    cin >> accNo;

                    found = 0;

                    for (int i = 0; i < totalAccounts; i++)
                    {
                        if (accountNumber[i] == accNo)
                        {
                            found = 1;
                            break;
                        }
                    }

                    if (found == 1)
                    {
                        cout << "Account Number Already Exists!\n";
                        break;
                    }

                    accountNumber[totalAccounts] = accNo;

                    cout << "Enter Account Holder Name (Max 10 characters): ";
                    cin >> accountName[totalAccounts];

                    if (accountName[totalAccounts].length() > 10)
                    {
                        cout << "Name must not exceed 10 characters!\n";
                        break;
                    }

                    cout << "Enter Initial Balance: ";
                    cin >> balance[totalAccounts];

                    if (balance[totalAccounts] < 0)
                    {
                        cout << "Invalid Balance!\n";
                        break;
                    }

                    totalAccounts++;

                    cout << "\nAccount Created Successfully!\n";
                }
                else
                {
                    cout << "\nMaximum Account Limit Reached!\n";
                }

                break;
            }

            case 2:
            {
                if (totalAccounts == 0)
                {
                    cout << "\nNo Accounts Available!\n";
                }
                else
                {
                    cout << "\n===== ALL ACCOUNTS =====\n";

                    for (int i = 0; i < totalAccounts; i++)
                    {
                        cout << "\nAccount Number: "
                             << accountNumber[i];

                        cout << "\nAccount Holder: "
                             << accountName[i];

                        cout << "\nBalance: "
                             << balance[i] << endl;
                    }
                }

                break;
            }

            case 3:
            {
                cout << "\nEnter Account Number: ";
                cin >> accNo;

                found = 0;

                for (int i = 0; i < totalAccounts; i++)
                {
                    if (accountNumber[i] == accNo)
                    {
                        cout << "Enter Deposit Amount: ";
                        cin >> amount;

                        if (amount > 0)
                        {
                            balance[i] += amount;

                            cout << "\nMoney Deposited Successfully!\n";
                            cout << "New Balance: " << balance[i] << endl;
                        }
                        else
                        {
                            cout << "Invalid Amount!\n";
                        }

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    cout << "Account Not Found!\n";
                }

                break;
            }

            case 4:
            {
                cout << "\nEnter Account Number: ";
                cin >> accNo;

                found = 0;

                for (int i = 0; i < totalAccounts; i++)
                {
                    if (accountNumber[i] == accNo)
                    {
                        cout << "Enter Withdrawal Amount: ";
                        cin >> amount;

                        if (amount <= 0)
                        {
                            cout << "Invalid Amount!\n";
                        }
                        else if (amount > balance[i])
                        {
                            cout << "Insufficient Balance!\n";
                        }
                        else
                        {
                            balance[i] -= amount;

                            cout << "\nMoney Withdrawn Successfully!\n";
                            cout << "Remaining Balance: "
                                 << balance[i] << endl;
                        }

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    cout << "Account Not Found!\n";
                }

                break;
            }

            case 5:
            {
                cout << "\nEnter Account Number: ";
                cin >> accNo;

                found = 0;

                for (int i = 0; i < totalAccounts; i++)
                {
                    if (accountNumber[i] == accNo)
                    {
                        cout << "\nAccount Holder: "
                             << accountName[i];

                        cout << "\nAccount Number: "
                             << accountNumber[i];

                        cout << "\nCurrent Balance: "
                             << balance[i] << endl;

                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    cout << "Account Not Found!\n";
                }

                break;
            }

            case 6:
            {
                cout << "\nThank You for Using Our Bank System!\n";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice! Please Try Again.\n";
            }
        }

    } while (choice != 6);

    return 0;
}

