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
    if (!entry) {
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
        // infof("info");
        queues->tail->m_next = entry;
        switch (queues->tailflag) {
            case QUEUES_TAILFLAG_MBUF:
                queues->tail->m_nextflag = QUEUES_HEADFLAG_MBUF;
                debugf("%d", queues->tail->m_nextflag);
                break;
            case QUEUES_TAILFLAG_MBUFEX:
                queues->tailex->mex_nextflag = QUEUES_HEADFLAG_MBUF;
                debugf("%d", queues->tailex->mex_nextflag);
                break;
            default:
                break;
        }
    }
    queues->tail = entry;
    queues->tailflag = QUEUES_TAILFLAG_MBUF;
    if (!queues->head) {
        queues->head = entry;
        queues->headflag = QUEUES_HEADFLAG_MBUF;
    }
    queues->num++;
    debugf("data:%s,nextflag:%d,next:%s", queues->tail->m_data,
           queues->tail->m_nextflag, queues->tail->m_next);
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
        switch (queues->tailflag) {
            case QUEUES_TAILFLAG_MBUF:
                queues->tail->m_nextflag = QUEUES_HEADFLAG_MBUFEX;
                debugf("%d", queues->tail->m_nextflag);
                break;
            case QUEUES_TAILFLAG_MBUFEX:
                queues->tailex->mex_nextflag = QUEUES_HEADFLAG_MBUFEX;
                debugf("%d", queues->tailex->mex_nextflag);
                break;
            default:
                break;
        }
    }
    queues->tailex = entry;
    queues->tailflag = QUEUES_TAILFLAG_MBUFEX;
    if (!queues->headex) {
        queues->headex = entry;
        queues->headflag = QUEUES_HEADFLAG_MBUFEX;
    }
    queues->num++;
    debugf("data:%s,nextflag:%d,next:%p", queues->tailex->mex_data,
           queues->tailex->mex_nextflag, queues->tailex->mex_next);
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
            /*infof(
                "Return MBUFEnque because mbuftype does not match prepared "
                "values.");
            return MBUFEnqueue(queues, data);*/
            break;
    }
    return 0;
}

MBUF *MBUFDequeue(QUEUES *queues, uint8_t headflag, uint8_t tailflag) {
    MBUF *entry;
    MBUF *data;
    uint8_t nextheadflag;

    if (!queues) {
        switch (headflag) {
            case QUEUES_HEADFLAG_MBUF:
                if (!queues->head) return NULL;
                break;
            case QUEUES_HEADFLAG_MBUFEX:
                if (!queues->headex) return NULL;
        }
    }
    entry = queues->head;
    switch (entry->m_nextflag) {
        case QUEUES_HEADFLAG_MBUF:
            queues->head = entry->m_next;
            break;
        case QUEUES_HEADFLAG_MBUFEX:
            queues->headex = entry->m_next;
            break;
        default:
            queues->head = entry->m_next;
            break;
    }
    if ((!queues->head) || (!queues->headex)) {
        switch (tailflag) {
            case QUEUES_TAILFLAG_MBUF:
                debugf("queues are empty.");
                queues->tail = NULL;
                queues->tailex = NULL;
                queues->tailflag = 0;
                break;
            case QUEUES_TAILFLAG_MBUFEX:
                debugf("queues are empty.");
                queues->tail = NULL;
                queues->tailex = NULL;
                queues->tailflag = 0;
                break;
            default:
                errorf("tailflag does not match any prepared values.");
                break;
        }
    }
    queues->num--;
    // infof("%d", entry->m_nextflag);
    queues->headflag = entry->m_nextflag;
    data = entry;
    OSMemoryFree(entry);
    return data;
}

MBUF *MBUFEXDequeue(QUEUES *queues, uint8_t headflag, uint8_t tailflag) {
    MBUFEX *entry;
    MBUF *data;

    if (!queues) {
        switch (headflag) {
            case QUEUES_HEADFLAG_MBUF:
                if (!queues->head) return NULL;
                break;
            case QUEUES_HEADFLAG_MBUFEX:
                if (!queues->headex) return NULL;
        }
    }
    entry = queues->headex;
    switch (entry->mex_nextflag) {
        case QUEUES_HEADFLAG_MBUF:
            queues->head = entry->mex_next;
            break;
        case QUEUES_HEADFLAG_MBUFEX:
            queues->headex = entry->mex_next;
            break;
        default:
            queues->headex = entry->mex_next;
            break;
    }

    if ((!queues->head) || (!queues->headex)) {
        switch (tailflag) {
            case QUEUES_TAILFLAG_MBUF:
                debugf("queues are empty.");
                queues->tail = NULL;
                queues->tailex = NULL;
                queues->tailflag = 0;
                break;
            case QUEUES_TAILFLAG_MBUFEX:
                debugf("queues are empty.");
                queues->tail = NULL;
                queues->tailex = NULL;
                queues->tailflag = 0;
                break;
            default:
                errorf("tailflag does not match any prepared values.");
                break;
        }
    }
    queues->num--;
    // infof("%d", entry->mex_nextflag);
    queues->headflag = entry->mex_nextflag;
    data = OSMemoryAlloc(sizeof(*data));
    data->m_data = entry->mex_data;
    // debugf("%s", data->m_data);
    OSMemoryFree(entry);
    return data;
}

void *QueueDequeue(QUEUES *queues) {
    switch (queues->headflag) {
        case QUEUES_HEADFLAG_MBUF:
            // infof("info");
            return MBUFDequeue(queues, queues->headflag, queues->tailflag);
            break;
        case QUEUES_HEADFLAG_MBUFEX:
            // infof("info");
            return MBUFEXDequeue(queues, queues->headflag, queues->tailflag);
            break;

        default:
            infof(
                "Return MBUFDequeue because mbuftype does not "
                "match prepared "
                "values.");
            /*
            return MBUFDequeue(queues, queues->headflag, queues->tailflag);
            */
            break;
    }
}