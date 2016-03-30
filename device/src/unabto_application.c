/**
 *  uNabto application logic implementation
 */

#include "unabto/unabto_app.h"
#include <stdio.h>

uint32_t gstate = 0, gtemp = 0, gmode = 0;

application_event_result application_event(application_request* request, buffer_read_t* read_buffer, buffer_write_t* write_buffer) {

    NABTO_LOG_INFO(("Nabto application_event: %u", request->queryId));

    switch(request->queryId) {
        // nabto_heatpump_get_state.json
        case 10: {
            if (!buffer_write_uint32(write_buffer, gstate)) return AER_REQ_RSP_TOO_LARGE;

            return AER_REQ_RESPONSE_READY;
        }
        // nabto_heatpump_set_state.json
        case 20: {
            uint32_t state;

            if (!buffer_read_uint32(read_buffer, &state)) return AER_REQ_TOO_SMALL;

            gstate = state;

            return AER_REQ_RESPONSE_READY;
        }
        // nabto_heatpump_get_temp.json
        case 30: {
            if (!buffer_write_uint32(write_buffer, gtemp)) return AER_REQ_RSP_TOO_LARGE;

            return AER_REQ_RESPONSE_READY;
        }
        // nabto_heatpump_set_temp.json
        case 40: {
            uint32_t temp;

            if (!buffer_read_uint32(read_buffer, &temp)) return AER_REQ_TOO_SMALL;

            gtemp = temp;

            return AER_REQ_RESPONSE_READY;
        }
        // nabto_heatpump_get_mode.json
        case 50: {
            if (!buffer_write_uint32(write_buffer, gmode)) return AER_REQ_RSP_TOO_LARGE;

            return AER_REQ_RESPONSE_READY;
        }
        // nabto_heatpump_set_mode.json
        case 60: {
            uint32_t mode;

            if (!buffer_read_uint32(read_buffer, &mode)) return AER_REQ_TOO_SMALL;

            gmode = mode;

            return AER_REQ_RESPONSE_READY;
        }
    }
    return AER_REQ_INV_QUERY_ID;
}
