
/**
 *  Implementation of main for uNabto SDK
 */

#include "unabto/unabto_env_base.h"
#include "unabto/unabto_common_main.h"
#include "unabto/unabto_logging.h"
#include "unabto_version.h"
#include "modules/cli/unabto_args.h"

void nabto_yield(int msec);

int main(int argc, char* argv[])
{
    nabto_main_setup* nms = unabto_init_context();

    if (!check_args(argc, argv, nms)) {
        return 1;
    }

    NABTO_LOG_INFO(("Identity: '%s'", nms->id));
    NABTO_LOG_INFO(("Program Release %" PRIu32 ".%" PRIu32, RELEASE_MAJOR, RELEASE_MINOR));
    NABTO_LOG_INFO(("Buffer size: %" PRIsize, nms->bufsize));

    if (!unabto_init()) {
        NABTO_LOG_FATAL(("Failed at nabto_main_init"));
    }

    while (true) {
        unabto_tick();
        nabto_yield(10);
    }

    unabto_close();
    return 0;
}

void nabto_yield(int msec)
{
#ifdef WIN32
    Sleep(msec);
#elif defined(__MACH__)
    if (msec) usleep(1000*msec);
#else
    if (msec) usleep(1000*msec); else sched_yield();
#endif
}
