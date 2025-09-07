#include <unistd.h>
#include <fcntl.h>
#include <string>
#define DEBUG_LOGS 1
#define RUNTIME_LOGS 1
#include "../include/ErrorReport.hpp"



int main() {
    const std::string file_name = "disk.img";
    int file = open(file_name.c_str(), O_RDWR);
    if(file <= 0)
        DLOG(ERROR, "failed to open file " + file_name);
        LOG(ERROR, "<runtime> failed to open file " + file_name);
        return 1;

    close(file);
    return 0;
}
