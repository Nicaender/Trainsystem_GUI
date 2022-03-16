#include <iostream>
#include <station.h>
#include <time.h>
#include <queue>
#include <windows.h>

using namespace std;

int main()
{
    srand(time(0));
    Station station;
    queue<Train*> waiting_list;
    queue<Train*> out_list;
    Train* list_trains[10];
    int delay;
    for(int i = 0; i < 10; i++)
    {
        Train* enter = new Train(i+1);
        list_trains[i] = enter;
    }

    int current_time = time(NULL);
    int beginning = current_time;
    for(int i = 0; i < 10; i++)
    {
        list_trains[i]->setIn_time(current_time + i * 20); // setiap kereta masuk di kelipatan ke 5
    }

    while(true)
    {
        Sleep(1000);
        current_time = time(NULL); // set waktu baru
        std::cout << "Waktu sekarang " << current_time - beginning << '\n';
        for(int i = 0; i < 10; i++)
        {
            if(current_time == list_trains[i]->getIn_time()) // kalau jam kereta = jam sekarang, maka dimasukkin ke waiting list
            {
                waiting_list.push(list_trains[i]);
            }
        }
        if(delay != 0)
            delay--;
        if(delay == 0)
        {
            if(station.check_slot()) // selama station nya masih ada slot, maka bisa masuk kereta
                if(!waiting_list.empty())
                    if(station.put_train(waiting_list.front(), current_time, beginning))
                    {
                        waiting_list.pop();
                        delay = 5;
                    }
        }

        station.check_which_train(out_list, current_time);
        if(!out_list.empty()) // selama ada yang mau keluar, silahkan keluar
            if(station.remove_train(out_list.front(), current_time, beginning))
                out_list.pop();
    }

    return 0;
}
