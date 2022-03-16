#include "train.h"

Train::Train(int x)
{
    this->id = x;
}

int Train::getId() const
{
    return id;
}

void Train::setId(int newId)
{
    id = newId;
}

int Train::getIn_time() const
{
    return in_time;
}

void Train::setIn_time(int newIn_time)
{
    in_time = newIn_time;
}

int Train::getOut_time() const
{
    return out_time;
}

void Train::setOut_time(int newOut_time)
{
    out_time = newOut_time;
}
