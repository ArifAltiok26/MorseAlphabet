#pragma once
#include "MorseTree.h"
class Application{
    MorseTree m_tree;
    public:
    void help()const;
    MorseTree init_morse_alphabet();
    void demo()const;
    void mainloop()const;
    void beep(int sound_time,int sleep_time=0)const;
    void play(const std::string& encoding_value)const;
    void run(int argc,char** argv);
};
