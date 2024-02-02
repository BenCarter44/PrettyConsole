#include "inputHandler.h"


// https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
char InputHandler_getch()
{
    #ifdef LINUX
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
    {
        perror("tcsetattr()");
    }
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
    {
        perror("tcsetattr ICANON");
    }
    if (read(0, &buf, 1) < 0)
    {
        perror ("read()");
    }
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
    {
        perror ("tcsetattr ~ICANON");
    }
    return (buf);
    #else
    return 0;
    #endif
}

void InputHandler::listeningThread()
{
    using namespace std::this_thread;
    using namespace std::chrono;

    do 
    {
        char c = InputHandler_getch();
        if(c != 0)
        {
            inputBuffer.push(c);
        }
        else
        {
            sleep_for(milliseconds(50));
        }
    }
    while(listen);
}

InputHandler::InputHandler()
{
    inputBuffer = queue<char>();
    listen = false;
}

void InputHandler::startListening()
{
    if(listen)
    {
        return;
    }
    using namespace std;
    listen = true;

    listenThread = new thread(&InputHandler::listeningThread, this);  
}

void InputHandler::stopListening()
{
    if(!listen)
    {
        return;
    }
    listen = false;
    listenThread->join();
    delete listenThread;
}

bool InputHandler::isListening()
{
    return listen;
}

int InputHandler::isAvailable()
{
    return inputBuffer.size();
}

char InputHandler::peek()
{
    return inputBuffer.front();
}

char InputHandler::read()
{
    if(inputBuffer.size() == 0)
    {
        return 0;
    }

    char c = inputBuffer.front();
    inputBuffer.pop();
    return c;
}

// Slower, O(n)
void InputHandler::clear()
{
    while(inputBuffer.size() > 0)
    {
        inputBuffer.pop();
    }
}