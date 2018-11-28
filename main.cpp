#include <ServerBoy.h>
#include <pipe/App.hpp>

int main()
{
    dan::app::App stApp("./demo", dan::app::appout > dan::proxy::ServerBoy::stOut, dan::app::appin < dan::proxy::ServerBoy::stIn);

    if(stApp.Running())
    {
        dan::proxy::ServerBoy stServerBoy;
        stServerBoy.Run();
    }

    int iExitCode = 0;
    stApp.Wait(iExitCode);
}



/*

namespace 
{
    ::pid_t stChildPid;
    int iExit = 0;
}

int main()
{
    if (::pipe(dan::proxy::ServerBoy::ReadPipeFds) == -1 || ::pipe(dan::proxy::ServerBoy::WritePipeFds) == -1)
    {
        printf("ERROR: pipe init failed\n");
        exit(-1);
    }

    //
    switch(stChildPid = ::fork())
    {
        case -1:
        {
            ::exit(-1);
        }
        case 0:
        {
            // child p
            ::setbuf(stdout, NULL);
            
            if(::dup2(dan::proxy::ServerBoy::ReadPipeFds[0], STDIN_FILENO) == -1 || ::dup2(dan::proxy::ServerBoy::WritePipeFds[1], STDOUT_FILENO) == -1)
            {
                printf("ERROR: child process bind to pipe failed\n");
                ::exit(7);
            }
            else
            {
                ::close(dan::proxy::ServerBoy::ReadPipeFds[1]);
                ::close(dan::proxy::ServerBoy::WritePipeFds[0]);
            }
            //TODO 执行app
            char* szArg = NULL;

            if(::execv("./demo", &szArg) == -1)
            {
                printf("error exec: %s\n",::strerror(errno));
            }
            ::exit(7);

        }
        default:
        {
            // parent p

            ::close(dan::proxy::ServerBoy::ReadPipeFds[0]);
            ::close(dan::proxy::ServerBoy::WritePipeFds[1]);
            ::close(STDIN_FILENO);

            // 从WritePipeFd[0] 读
            // 往ReadPipeFds[1] 写
            dan::proxy::ServerBoy stServerBoy;
            stServerBoy.Run();

            ::wait(&iExit);
            if(iExit == 7)
            {

            }
        }
    }

   // dan::proxy::ServerBoy stServerBoy;
   // stServerBoy.Run();
}


*/
/*
int main()
{
    const char* str = "from parent's message\n";
    int stat;
    pid_t pid;
    int fd[2];

    pipe(fd);

    pid = fork();
    if(0 == pid)//child read
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);

                     
            char* szArg = NULL;
            if(::execv("./app", &szArg) == -1)
            {
                printf("error exec: %s\n",::strerror(errno));
              //  printf("ERROR: exec failed\n");
            }

          
    }
    else//parent write
    {

        close(fd[0]);
        int old = dup(STDOUT_FILENO);
        int iNew = dup2(fd[1], STDOUT_FILENO);

                                                                            
        write(fd[1], str, strlen(str)+1);


        dup2(old, iNew);//恢复重定向

        wait(&stat);//
        if ( WIFEXITED(stat) )
        {
            printf("child exited with code:%d\n", WEXITSTATUS(stat));
        }

        close(fd[1]);

        exit(0);
    }
}

*/
