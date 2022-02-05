#include <iostream>
using namespace std;

class TV
{
    friend class TVController;

public:
    TV(int volume, int chanel) : volume_(volume), chanel_(chanel)
    {
    }

private:
    int volume_;
    int chanel_;
};

class TVController
{
public:
    void VolumeUp(TV &tv)
    {
        tv.volume_ += 1;
    }

    void VolumeDown(TV &tv)
    {
        tv.volume_ -= 1;
    }

    void ChanelUp(TV &tv)
    {
        tv.chanel_ += 1;
    }

    void ChanelDown(TV &tv)
    {
        tv.chanel_ -= 1;
    }
};

int main()
{
    TV tv(1, 1);
    TVController tc;
    tc.VolumeDown(tv);
    return 0;
}