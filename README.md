To enable logs define DEBUG_LOGS as 1, BEFORE including the header
<br> <br> <br>
ex:
<br> <br>
#define DEBUG_LOGS 1
<br>
#include "../include/ErrorReport.hpp"
<br> <br>
(P.S. I just recently learned that you can also add it as a flag in your makefile: "-DDEBUG_LOGS=1")
<br> <br>
then as needed call LOG(status_level, message)
<br>
status levels are: ERROR, WARNING or INFO
<br> <br>
DEBUG_LOGS is defined to 0 by default

