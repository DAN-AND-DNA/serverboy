#include <pipe/App.hpp>
#include <iostream>

int main()
{
    dan::pipe::PosixPipeistream<char> stOut;
    dan::pipe::PosixPipeostream<char> stIn;

    dan::app::App app("./app1", dan::app::appout > stOut, dan::app::appin < stIn);

    std::cout<< app.Pid()<<std::endl;

    std::cout<<"app start\n";
    while(app.Running())
    {
        stIn << "dddddddddd" << std::endl;
        std::string value;
        std::cout<<"d1.5\n";
        stOut >> value;

        if(value == "error")
        {
            std::cout<<app.StrError()<<std::endl;
            break;
        }
    }

    std::cout<<"app stop\n";
    int iExitCode = 0;
    app.Wait(iExitCode);
}
