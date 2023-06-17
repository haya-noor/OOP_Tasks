#include <iostream>
using namespace std;

class bankAccount
{
private:
    int account_number;
    double balance;

public:
    bankAccount(int account_number, double balance)
    {
        this->account_number = account_number;
        this->balance = balance;
    }

    void set_account_number(int account_number)
    {
        this->account_number = account_number;
    }

    int get_account_number()
    {
        return account_number;
    }

    double get_balance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        if(amount > 0)
        {
            balance += amount;
        }
        else 
           cout<<"Amount must be greater than 0\n";
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds"<<endl;
        }
    }

    void print_account_info()
    {
        cout << "Account Number: " << account_number <<endl;
        cout << "Balance: " << balance <<endl;
    }
    friend class checkingAccount;
    friend class savingsAccount;
};

class checkingAccount : public bankAccount
{
private:
    double interest_rate;
    double minimum_balance;
    double service_charges;

public:
    checkingAccount(int account_number, double balance, double interest_rate, double minimum_balance, double service_charges)
        : bankAccount(account_number, balance)
    {
        this->interest_rate = interest_rate;
        this->minimum_balance = minimum_balance;
        this->service_charges = service_charges;
    }

    void set_interest_rate(double interest_rate)
    {
        this->interest_rate = interest_rate;
    }

    double get_interest_rate()
    {
        return interest_rate;
    }

    void set_minimum_balance(double minimum_balance)
    {
        this->minimum_balance = minimum_balance;
    }

    double get_minimum_balance()
    {
        return minimum_balance;
    }

    void set_service_charges(double service_charges)
    {
        this->service_charges = service_charges;
    }

    double get_service_charges()
    {
        return service_charges;
    }

    void post_interest()
    {
        double interest = balance * (interest_rate / 100);
        balance += interest;
    }

    bool check_minimum_balance()
    {
        if (balance < minimum_balance)
        {
            return true;
        }
        return false;
    }

    void write_check(double amount)
    {
        if (!check_minimum_balance())
        {
            withdraw(amount);
        }
        else
        {
            cout << "Cannot write check. Balance is below minimum." <<endl;
        }
    }

    void withdraw(double amount)
    {
        if (!check_minimum_balance())
        {
            bankAccount::withdraw(amount);
            deduct_service_charges();
        }
        else
        {
            cout << "Cannot withdraw. Balance is below minimum." <<endl;
        }
    }

    void deduct_service_charges()
    {
        balance -= service_charges;
    }

    void print_account_info()
    {
        bankAccount::print_account_info();
        cout << "Interest Rate: " << interest_rate <<endl;
        cout << "Minimum Balance: " << minimum_balance <<endl;
        cout << "Service Charges: " << service_charges <<endl;
    }
};

class savingsAccount : public bankAccount
{
private:
    double interest_rate;

public:
    savingsAccount(int account_number, double balance, double interest_rate): bankAccount(account_number, balance)
    {
        this->interest_rate = interest_rate;
    }

    void set_interest_rate(double interest_rate)
    {
        this->interest_rate = interest_rate;
    }

    double get_interest_rate()
    {
        return interest_rate;
    }

    void post_interest()
    {
        double interest = balance * (interest_rate / 100);
        balance += interest;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            bankAccount::withdraw(amount);
        }
        else
        {
            cout << "Insufficient funds" <<endl;
        }
    }

    void print_account_info()
    {
        bankAccount::print_account_info();
        cout << "Interest Rate: " << interest_rate <<endl;
    }
};

int main()
{
    // Test code for checkingAccount
    checkingAccount checking(12345, 1000.0, 2.5, 500.0, 10.0);
    checking.print_account_info();

    cout << "Depositing $500..." << endl;
    checking.deposit(500.0);
    checking.print_account_info();

    cout << "Withdrawing $200..." <<endl;
    checking.withdraw(200.0);
    checking.print_account_info();

    cout << "Writing a check for $800..." <<endl;
    checking.write_check(800.0);
    checking.print_account_info();

    cout << "Withdrawing $200..." <<endl;
    checking.withdraw(200.0);
    checking.print_account_info();

    // Test code for savingsAccount
    savingsAccount savings(54321, 5000.0, 1.5);
    savings.print_account_info();

    cout << "Depositing $1000..." <<endl;
    savings.deposit(1000.0);
    savings.print_account_info();

    cout << "Withdrawing $2000..." <<endl;
    savings.withdraw(2000.0);
    savings.print_account_info();

    cout << "Posting interest..." <<endl;
    savings.post_interest();
    savings.print_account_info();

    return 0;
}
