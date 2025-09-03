To enable logs define DEBUG_LOGS as 1, BEFORE including the header <br> <br>

ex:

#define DEBUG_LOGS 1

#include "../include/ErrorReport.hpp" <br> <br> <br>


then as needed call LOG(status_level, message)

status_level: ERROR, WARNING, INFO
<br> <br>
DEBUG_LOGS is defined to 0 by default

