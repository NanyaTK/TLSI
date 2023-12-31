/*
 * Copyright (C) 2023 NanyaTK ( https://github.com/NanyaTK )
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "src/memory.h"

#include "src/OS/os.h"
#include "src/type.h"
#include "src/util.h"

int QueueInit(QUEUES *queues) { return QueueInitTest(queues); }

int QueueInitTest(QUEUES *queues) {
    queues->head = NULL;
    queues->tail = NULL;
    queues->num = 0;
    return 0;
}

void *MBUFEnqueue(QUEUES *queues, MBUF *data) {
    if (!queues) {
        errorf("queues does not initialized.");
        return NULL;
    }
    MBUF *entry;
    entry = OSMemoryAlloc(sizeof(*entry));
    if (!queues) {
        errorf("OSMemoryAlloc() failure. (MBUF *entry)");
        return NULL;
    }
    entry->m_next = NULL;
    entry->m_len = data->m_len;
    entry->m_data = data->m_data;
    entry->m_type = data->m_type;
    entry->m_flags = data->m_flags;
    entry->m_nextpkt = data->m_nextpkt;

    if (queues->tail) {
        queues->tail->m_next = entry;
    }
    queues->tail = entry;
    if (!queues->head) {
        queues->head = entry;
    }
    queues->num++;
    debugf("%s", entry->m_data);
    return data;
}

void *MBUFEXEnqueue(QUEUES *queues, void *data) {
    if (!queues) {
        errorf("queues does not initialized.");
        return NULL;
    }
    MBUFEX *entry;
    entry = OSMemoryAlloc(sizeof(*entry));
    if (!entry) {
        errorf("OSMemoryAlloc() failure. (MBUFEX *entry)");
        return NULL;
    }
    entry->mex_next = NULL;
    entry->mex_data = data;
    if (queues->tailex) {
        queues->tailex->mex_next = entry;
    }
    queues->tailex = entry;
    if (!queues->headex) {
        queues->headex = entry;
    }
    queues->num++;
    debugf("%s", entry->mex_data);
    return data;
}

void *QueueEnqueue(QUEUES *queues, void *data, uint8_t mbuftype) {
    if (!queues) {
        return NULL;
    }
    switch (mbuftype) {
        case 1:
            return MBUFEnqueue(queues, data);
            break;
        case 2:
            return MBUFEXEnqueue(queues, data);
            break;
        default:
            infof(
                "Return MBUFEnque because mbuftype does not match prepared "
                "values.");
            return MBUFEnqueue(queues, data);
            break;
    }
    /*
    MBUF *entry;
    entry = OSMemoryAlloc(sizeof(entry));
    if (!entry) {
        errorf("OSMemoryAlloc() failure");
    }
    MBUFEnque(entry, data, len, type, flags);
    return entry;
    */
    return 0;
}
