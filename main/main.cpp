#include <iostream>
using namespace std;

class Student
{
    string name;
    int* rates;
    int numOfRates;
public:
    Student()
    {
        name = "Alex";
        numOfRates = 10;
        rates = new int[numOfRates];

        for (int i = 0; i < numOfRates; i++)
        {
            rates[i] = rand() % 100;
        }
    }

    Student(const Student& s)
    {
        name = s.name;
        numOfRates = s.numOfRates;
        
        if (rates != nullptr)
            delete[] rates;

        rates = new int[numOfRates];

        for (int i = 0; i < numOfRates; i++)
        {
            rates[i] = s.rates[i];
        }
    }

    Student& operator = (const Student& s)
    {
        if (&s != this)
        {
            name = s.name;
            numOfRates = s.numOfRates;

            if (rates != nullptr)
                delete[] rates;

            rates = new int[numOfRates];

            for (int i = 0; i < numOfRates; i++)
            {
                rates[i] = s.rates[i];
            }
        }
        return *this;
    }

    ~Student()
    {
        delete[] rates;
    }

    string GetName()const
    {
        return name;
    }
    int* GetRates()const
    {
        return rates;
    }
    int GetNumOfRates()const
    {
        return numOfRates;
    }
};

int main()
{
    srand(time(0));

    Student obj1;

    Student obj2 = obj1;

    Student obj3;
    obj3 = obj2;

    cout << "Obj1:\n";
    for (int i = 0; i < obj1.GetNumOfRates(); i++)
    {
        cout << obj1.GetRates()[i] << " ";
    }
    
    cout << "\n\nObj2:\n";
    for (int i = 0; i < obj2.GetNumOfRates(); i++)
    {
        cout << obj2.GetRates()[i] << " ";
    }

    cout << "\n\nObj3:\n";
    for (int i = 0; i < obj3.GetNumOfRates(); i++)
    {
        cout << obj3.GetRates()[i] << " ";
    }
    cout << "\n\n";
}