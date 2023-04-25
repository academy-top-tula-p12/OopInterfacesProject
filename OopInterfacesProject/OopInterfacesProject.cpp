#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class IMovable
{
public:
    virtual void Move() = 0;
};

class ISpeedable
{
public:
    virtual void SetSpeed(double) = 0;
    virtual double GetSpeed() = 0;
};

class ISoundable
{
public:
    virtual double GetVolume() = 0;
    virtual double VolumeUp() = 0;
    virtual double VolumeDown() = 0;
};

class Treadmill : public ISpeedable
{

};

class Car : public ISpeedable, public IMovable
{

};

class MediaPlayer : public ISpeedable, public ISoundable
{

};

class Radio : public ISoundable
{

};

class Wheel : public IMovable
{

};


class ILogger
{
public:
    virtual void Log(string message) = 0;
};

class ConsoleLogger : public ILogger
{
public:
    void Log(string message) override
    {
        cout << "log: " << message << "\n";
    }
};

class FileLogger : public ILogger
{
    string fileName;
public:
    FileLogger(string fileName) : fileName{ fileName } {}

    void Log(string message) override
    {
        FILE* file = fopen(fileName.c_str(), "a+");
        fputs(message.c_str(), file);
        fputc('\n', file);
        fclose(file);
    }
};

void Function(double x, ILogger* logger)
{
    string message = "sqrt x: " + to_string(sqrt(x));
    logger->Log(message);
}

int main()
{
    ILogger* logger = new FileLogger("file.log");

    for (int i = 0; i < 5; i++)
        Function(rand(), logger);
}
