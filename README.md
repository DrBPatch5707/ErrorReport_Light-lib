# ErrorReport Logging Library

A lightweight C++ header-only logging utility that lets you toggle
**debug logs** and **runtime logs** independently at compile time.

## Features

-   **Compile-time toggles**: Logging code is completely removed when
    disabled.
-   **Separate log categories**:
    -   `DLOG(...)` → Debug logs, controlled with `DEBUG_LOGS`.
    -   `LOG(...)` → Runtime logs, controlled with `RUNTIME_LOGS`.
-   **Three status levels**: `ERROR`, `WARNING`, `INFO`.
-   **Zero-overhead when disabled** (macros expand to no-ops).

------------------------------------------------------------------------

## Setup

Enable desired logs before including the header by defining macros:

``` cpp
#define DEBUG_LOGS 1
#define RUNTIME_LOGS 0
#include "../include/ErrorReport.hpp"
```

Alternatively, you can pass them as **compiler flags**:

``` sh
g++ main.cpp -DDEBUG_LOGS=1 -DRUNTIME_LOGS=1
```

By default:

-   `DEBUG_LOGS = 0`
-   `RUNTIME_LOGS = 0`

------------------------------------------------------------------------

## Usage

Use `DLOG` for debug logging and `LOG` for runtime logging:

``` cpp
DLOG(INFO, "This is a debug-only log");
LOG(ERROR, "This is a runtime log");
```

Both take a `status` (`ERROR`, `WARNING`, `INFO`) and a `std::string`
message.

------------------------------------------------------------------------

## Example

``` cpp
#include <unistd.h>
#include <fcntl.h>
#include <string>

#define DEBUG_LOGS 1
#define RUNTIME_LOGS 1
#include "../include/ErrorReport.hpp"

int main() {
    const std::string file_name = "disk.img";
    int file = open(file_name.c_str(), O_RDWR);
    if(file <= 0) {
        DLOG(ERROR, "failed to open file " + file_name);
        LOG(ERROR, "<runtime> failed to open file " + file_name);
        return 1;
    }

    close(file);
    return 0;
}
```

------------------------------------------------------------------------

## Notes

-   If both systems are disabled, the macros expand to no-ops, so there
    is **no runtime cost**.
-   You can mix debug and runtime logs as needed. For example, keep
    debug off in production but leave runtime logs enabled.
<br> <br> <br> <br> <br>
**I generated this file with AI**
