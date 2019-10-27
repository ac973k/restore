#include <fstream>
#include <cstring>

#include "restore.h"

restore::restore(std::string fileBlock)
{
    fBlock = fileBlock;
}

restore::~restore()
{

}

void restore::flashBlock()
{
    if(fBlock == "loader")
    {
        std::cout << "Open...";

        command = "/dev/block/mmcblk0boot0";
        source = "/sdcard/MotoRestore/loader.bin";

        std::ofstream block(command, std::ofstream::binary); //write
        std::ifstream bkp(source, std::ifstream::binary); //read

        std::cout << "\nWrite...";

        block << bkp.rdbuf();

        block.close();
        bkp.close();

        std::cout << "\nOk..." << std::endl;
    }
    else if(fBlock == "help")
    {
        std::cout << "Utility Restore special created for device Motorola Moto C 4G(Namath)." << std::endl;

        std::cout << "Example: restore boot" << std::endl;

        std::cout << "Keys: " << std:: endl
                  << "boot - restore boot.img" << std::endl
                  << "efuse- restore efuse.img" << std::endl
                  << "expdb - restore expdb.img" << std::endl
                  << "flashinfo - restore flashinfo.img" << std::endl
                  << "frp - restore frp.img" << std::endl
                  << "keystore - restore keystore.img" << std::endl
                  << "lk - restore lk.img" << std::endl
                  << "logo - retore logo.img" << std::endl
                  << "metadata - restore metadata.img" << std::endl
                  << "nvdata - restore nvdata.img" << std::endl
                  << "nvram - restore nvram.img" << std::endl
                  << "oemkeystore - restore oemkeystore.img" << std::endl
                  << "para - restore para.img" << std::endl
                  << "proinfo - restore proinfo.img" << std::endl
                  << "protect1 - restore protect1.img" << std::endl
                  << "protect2 - restore protect2.img" << std::endl
                  << "recovery - restore recovery.img" << std::endl
                  << "seccfg - restore seccfg.img" << std::endl
                  << "secro - restore secro.img" << std::endl
                  << "system - restore system.img" << std::endl
                  << "tee1 - restore tee1.img" << std::endl
                  << "tee2 - restore tee2.img" << std::endl;
    }
    else
    {
        std::cout << "\nOpen...";

        command = "/dev/block/platform/mtk-msdc.0/11230000.msdc0/by-name/" + fBlock;
        source = "/sdcard/MotoRestore/" + fBlock + ".img";

        std::ofstream block(command, std::ofstream::binary); //write
        std::ifstream bkp(source, std::ifstream::binary); //read

        std::cout << "\nWrite...";

        block << bkp.rdbuf();

        block.close();
        bkp.close();

        std::cout << "\nOk..." << std::endl;
    }
}
