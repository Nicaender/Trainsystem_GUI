#ifndef TRAIN_H
#define TRAIN_H


class Train
{
public:
    Train(int x);
    int getId() const;
    void setId(int newId);

    int getIn_time() const;
    void setIn_time(int newIn_time);

    int getOut_time() const;
    void setOut_time(int newOut_time);

private:
    int id;
    int in_time;
    int out_time;
};

#endif // TRAIN_H
