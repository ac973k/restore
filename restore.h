#ifndef RESTORE_H
#define RESTORE_H

#include <iostream>

class restore
{
private:
    std::string fBlock;

    std::string command;
    std::string source;

public:
    restore(std::string fileBlock);

    ~restore();

    void flashBlock();
};

#endif // RESTORE_H
