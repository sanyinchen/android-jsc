


add_library(bridge
        SHARED
        bridge.cpp
        )


target_link_libraries(bridge
        jscwrap
        log)