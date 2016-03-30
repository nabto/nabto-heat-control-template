/**
 *  uNabto application logic implementation
 */

#include "unabto/unabto_app.h"
#include <stdio.h>

application_event_result application_event(application_request* request, buffer_read_t* read_buffer, buffer_write_t* write_buffer) {

    NABTO_LOG_ERROR(("No functionality added!"));

    switch(request->queryId) {
        case 10: {
            return AER_REQ_RESPONSE_READY;
        }
        case 20: {
            return AER_REQ_RESPONSE_READY;
        }
    }
    return AER_REQ_INV_QUERY_ID;
}
