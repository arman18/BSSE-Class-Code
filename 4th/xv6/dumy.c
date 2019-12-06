#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int k, n, id;
    double x=0, z;

    if(argc < 2)
        n = 4;  // default value
    else
        n = atoi(argv[1]);  // from user input
    if(n<0 || n>100)
        n = 2;

  //  if(argc < 3)
    //    d = 1.0;
  //  else
   //     d = atoi(argv[2]);

    x = 0;
    id = 0;
    
    for(k=0; k<n; k++)
    {
        
        id = fork();
        //printf(1,"Pn= %d pid= %d id= %d\n",n,getpid(),id);
        if(id < 0)
            printf(1, "%d failed in fork!\n", getpid());
        else if(id > 0)
        {   // Parent
            printf(1, "Parent %d creating child %d\n", getpid(), id);
            wait();
            //printf(1,"parent runnung %d\n",getpid());
        }
        else
        {   // Child
        //printf(1,"CHn= %d pid= %d\n",n,getpid());
            printf(1, "Child %d created\n", getpid());
            for(z=0;z<8000000.0;z+=.001)
                x = x + 3.14*89.64; // Useless calculations to consume CPU time
                //printf(1,"chield complete %d\n",getpid());
            break;
        }
    }
    exit();
}
