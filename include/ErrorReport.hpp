#ifndef ERRORREPORT_HPP
#define ERRORREPORT_HPP
#endif

#ifndef DEBUG_LOGS
    #define DEBUG_LOGS 0
#endif

#include <iostream>
#include <string>

#if DEBUG_LOGS == 1

    enum status {
    ERROR,
    INFO,
    WARNING
    };

    struct ErrorReport
    {
        
        static void log(status status_level, std::string message) {
            
            std::cout << '[' << STATUS_LEVELS[status_level] << "] " << message << "..." << std::endl;
            return;
        }
        
        private:
        static const std::string STATUS_LEVELS[3];
    
    };

    const std::string ErrorReport::STATUS_LEVELS[3] = {
        "ERROR",
        "INFO",
        "WARNING"
    };

    #define LOG(status_level, message) ::ErrorReport::log((status_level), (message))
#else
    struct ErrorReport {};

    #define LOG(...) ((void)0)
#endif

