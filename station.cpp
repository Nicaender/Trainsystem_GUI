#include "station.h"

Station::Station()
{
    for(int i = 0; i < 4; i++)
    {
        trainList[i] = nullptr;
    }
}

bool Station::put_train(Train *input, const int &current_time, const int &beginning)
{
    for(int i = 0; i < 4; i++)
    {
        if(trainList[i] == nullptr)
        {
            this->trainList[i] = input;
            this->trainList[i]->setOut_time(current_time + 75); // keluar 20 detik setelah masuk
            std::cout << "Train " << this->trainList[i]->getId() << " is entering platform " << i + 1 << " at " << current_time - beginning;
            std::cout << " and should leave at " << this->trainList[i]->getOut_time() - beginning << '\n';
            return true;
        }
    }

    return false;
}

void Station::check_which_train(std::queue<Train *> &qt, const int &current_time)
{
    for(int i = 0; i < 4; i++)
    {
        if(trainList[i] && trainList[i]->getOut_time() == current_time)
        {
            qt.push(trainList[i]);
        }
    }
}

bool Station::remove_train(Train *input, const int &current_time, const int &beginning)
{
    for(int i = 0; i < 4; i++)
    {
        if(trainList[i] == input)
        {
            trainList[i]->setIn_time(current_time + 10); // masuk lagi setelah 10 detik
            std::cout << "Train " << this->trainList[i]->getId() << " is exiting platform " << i + 1 << " at " << current_time - beginning;
            std::cout << " and should coming back at " << this->trainList[i]->getIn_time() - beginning << '\n';
            trainList[i] = nullptr;
            return true;
        }
    }

    return false;
}

bool Station::check_slot()
{
    for(int i = 0; i < 4; i++)
    {
        if(trainList[i] == nullptr)
            return true;
    }
    return false;
}
