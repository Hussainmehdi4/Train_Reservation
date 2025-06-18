#include <iostream>
using namespace std;
class Train
{
    bool Seats[6][4];

public:
    Train()
    {
        cout << "\033[1;36m" << R"VOGON(
        __      __ ___     _       ___     ___   __  __    ___   
        \ \    / /| __|   | |     / __|   / _ \ |  \/  |  | __|  
         \ \/\/ / | _|    | |__  | (__   | (_) || |\/| |  | _|   
          \_/\_/  |___|   |____|  \___|   \___/ |_|__|_|  |___|  
    )VOGON";

        cout << "\033[1;35m" << R"VOGON(
        _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 
        "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-' 
)VOGON" << "\033[0m"
             << endl;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                Seats[i][j] = 0;
            }
        }
    }
    void Reserve_Seat(int row, int col)
    {
        row--;
        col--;
        if ((row >= 0 && row <= 5) && (col >= 0 && col <= 3))
        {
            if (Seats[row][col] != 1)
            {
                Seats[row][col] = 1;
                cout << "Your Seat in Row " << (row + 1) << " and column " << (col + 1) << " Reserved" << endl;
            }
            else
            {
                cout << "Seat is Already Reserved! Find Other" << endl;
            }
        }
        else
        {
            cout << "Invalid Input! Try Again" << endl;
        }
    }
    void Cancel_Seat(int row, int col)
    {
        row--;
        col--;
        if ((row >= 0 && row <= 5) && (col >= 0 && col <= 3))
        {
            if (Seats[row][col] != 0)
            {
                Seats[row][col] = 0;
                cout << "Seat Reservation Cancelled!" << endl;
            }
            else
            {
                cout << "Seat is Already free" << endl;
            }
        }
        else
        {
            cout << "Invalid Input Enter Again" << endl;
        }
    }
    void Check_Seat(int row, int col)
    {
        row--;
        col--;
        int choice = 0;
        if ((row >= 0 && row <= 5) && (col >= 0 && col <= 3))
        {
            if (Seats[row][col] != 1)
            {
                cout << "Seat is free to reserve." << endl;
                do
                {
                    cout << "Wanna Reserve?\n1) Yes 0) No" << endl;
                    cout << "Enter here : ";
                    cin >> choice;
                    if (choice == 1)
                    {
                        row++;
                        col++;
                        Reserve_Seat(row, col);
                        break;
                    }
                    else if (choice == 0)
                    {
                        cout << "No problem :)" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input Enter Again" << endl;
                    }
                } while (true);
            }
            else
            {
                cout << "Seat is already reserved" << endl;
            }
        }
        else
        {
            cout << "Invalid Input Enter Again" << endl;
        }
    }
    void ShowSeats()
    {

        cout << "\n     ";
        for (int col = 0; col < 4; col++)
        {
            cout << " Col " << col + 1 << " ";
        }
        cout << endl;

        cout << "    +" << string(31, '-') << "+" << endl;

        for (int i = 0; i < 6; i++)
        {
            cout << "Row " << i + 1 << " |";

            for (int j = 0; j < 4; j++)
            {
                if (Seats[i][j] == 1)
                    cout << "  \033[1;32m✓\033[0m   |";
                else
                    cout << "  \033[1;31mX\033[0m   |";
            }

            cout << endl;

            cout << "    +" << string(31, '-') << "+" << endl;
        }

        cout << "\n\033[1;32m✔ = Available\033[0m   \033[1;31mX = Reserveed\033[0m\n"
             << endl;
    }
};
int main()
{
    Train T;
    int row = 0, col = 0, choice = 0;
    do
    {
        cout << "============[ Choices ]============" << endl;
        cout << "1) Show All Seats\n2) Check Seat\n3) Reserve Seat\n4) Cancel Seat\n0) Exit\n";
        cout << "Enter Choice here : ";
        cin >> choice;
        cout << "===================================" << endl;
        switch (choice)
        {
        case 1:
            T.ShowSeats();
            break;
        case 2:
            cout << "Enter Row : ";
            cin >> row;
            cout << "Enter Column : ";
            cin >> col;
            T.Check_Seat(row, col);
            break;
        case 3:
            cout << "Enter Row : ";
            cin >> row;
            cout << "Enter Column : ";
            cin >> col;
            T.Reserve_Seat(row, col);
            break;
        case 4:
            cout << "Enter Row : ";
            cin >> row;
            cout << "Enter Column : ";
            cin >> col;
            T.Cancel_Seat(row, col);
            break;
        case 0:
            cout << "Exited Successfully!" << endl;
            cout << "===================================";
            break;
        default:
            cout << "Invalid Input! Enter Again\n";
        }
        if (!choice)
        {
            break;
        }

    } while (true);
    cout << "Bye" << endl;
    return 0;
}