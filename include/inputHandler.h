#ifndef INPUT_HANDLE_H
#define INPUT_HANDLE_H

#include "console.h"

#ifdef LINUX
#include <unistd.h>
#include <termios.h>
#endif

#include <queue>
#include <chrono>
#include <thread>


char InputHandler_getch();

class InputHandler
{
public:
    InputHandler();

    void startListening();
    void stopListening();
    bool isListening();

    int isAvailable();
    char peek();
    char read();
    void clear();
    
private:   
    bool listen;
    queue<char> inputBuffer;
    std::thread* listenThread;

    void listeningThread();
};


#endif