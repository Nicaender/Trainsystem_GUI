#ifndef STATION_H
#define STATION_H
#include <thread>
#include <train.h>
#include <iostream>
#include <queue>

class Station
{
public:
    Station();
    bool put_train(Train *input, const int &current_time, const int &beginning);
    void check_which_train(std::queue<Train*> &qt, const int &current_time);
    bool remove_train(Train *input, const int &current_time, const int &beginning);
    bool check_slot();

private:
    Train* trainList[4];
};

#endif // STATION_H
