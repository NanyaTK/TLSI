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

typedef struct queues {
    union {
        MBUF *head;
        MBUF2 *head2;
    };
    union {
        MBUF *tail;
        MBUF2 *tail2;
    };
} QUEUES;

int QueueInitTest(QUEUES *queues) {
    queues->head = NULL;
    queues->tail = NULL;
    return 0;
}

void *MBUFEnque(MBUF *entry, void *data, uint32_t len, uint16_t type,
                uint16_t flags) {
    entry->m_nextpkt = NULL;
    entry->m_data = data;
    entry->m_len = len;
    entry->m_type = type;
    entry->m_flags = flags;
    return 0;
}

void *MBUF2Enque(MBUF2 *entry) { return 0; }

void *QueueEnque(QUEUES *queues, void *data, uint32_t len, uint16_t type,
                 uint16_t flags, uint8_t mbuftype) {
    if (!queues) {
        return NULL;
    }
    /*switch (mbuftype) {
        case 1:
            MBUF *entry;
            entry = OSMemoryAlloc(sizeof(entry));
            if (!entry) {
                errorf("OSMemoryAlloc() failure");
            }
            MBUFEnque(entry, data, len, type, flags);
            return entry;
            break;
        case 2:
            MBUF2 *entry2;
            entry2 = OSMemoryAlloc(sizeof(entry2));
            if (!entry2) {
                errorf("OSMemoryAlloc() failure");
            }
            MBUF2Enque(entry2);
            return entry2;
            break;
        default:
            MBUF *entry_default;
            entry_default = OSMemoryAlloc(sizeof(entry_default));
            if (!entry_default) {
                errorf("OSMemoryAlloc() failure");
            }
            return entry_default;
            break;
    }*/
    MBUF *entry;
    entry = OSMemoryAlloc(sizeof(entry));
    if (!entry) {
        errorf("OSMemoryAlloc() failure");
    }
    MBUFEnque(entry, data, len, type, flags);
    return entry;

    return 0;
}
