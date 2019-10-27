#include "restore.h"

int main(int argc, char** argv)
{
    if(argc <= 1)
    {
        std::cerr << "Error! Example: restore recovery" << std::endl << "Used restore help" << std::endl;
    }

    restore rstr(argv[1]);
    rstr.flashBlock();

    return 0;
}
