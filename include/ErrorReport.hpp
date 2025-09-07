#ifndef ERRORREPORT_HPP
#define ERRORREPORT_HPP


#ifndef DEBUG_LOGS
    #define DEBUG_LOGS 0
#endif
#ifndef RUNTIME_LOGS
    #define RUNTIME_LOGS 0
#endif


#if RUNTIME_LOGS || DEBUG_LOGS

enum status {
    ERROR,
    INFO,
    WARNING
    };

#endif



#if DEBUG_LOGS

#include <iostream>
#include <string>



    struct ErrorReport
    {
        
        static void log(status status_level, std::string message) {
            
            std::cout << '[' << STATUS_LEVELS[status_level] << "] " << message << "..." << std::endl;
            return;
        }
        
        private:
        static const std::string STATUS_LEVELS[3];
    
    };

    inline const std::string ErrorReport::STATUS_LEVELS[3] = {
        "ERROR",
        "INFO",
        "WARNING"
    };

    #define LOG(status_level, message) ::ErrorReport::log((status_level), (message))
#else
    struct ErrorReport {};

    #define LOG(...) ((void)0)
#endif




#if RUNTIME_LOGS

#include <iostream>
#include <string>


    struct RuntimeReport
    {
        
        static void log(status status_level, std::string message) {
            
            std::cout << '[' << STATUS_LEVELS[status_level] << "] " << message << "..." << std::endl;
            return;
        }
        
        private:
        static const std::string STATUS_LEVELS[3];
    
    };

    inline const std::string RuntimeReport::STATUS_LEVELS[3] = {
        "ERROR",
        "INFO",
        "WARNING"
    };

    #define RTLOG(status_level, message) ::RuntimeReport::log((status_level), (message))
#else
    struct RuntimeReport {};

    #define RTLOG(...) ((void)0)
#endif
#endif //ERRORREPORT_HPP