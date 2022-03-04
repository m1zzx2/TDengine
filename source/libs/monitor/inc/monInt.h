/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _TD_MONITOR_INT_H_
#define _TD_MONITOR_INT_H_

#include "monitor.h"

#include "tarray.h"
#include "tlockfree.h"
#include "tjson.h"

typedef struct {
  int64_t   ts;
  ELogLevel level;
  char      content[MON_LOG_LEN];
} SMonLogItem;

typedef struct SMonInfo {
  SArray *logs;  // array of SMonLogItem
  SJson  *pJson;
} SMonInfo;

typedef struct {
  pthread_rwlock_t rwlock;
  SArray          *logs;  // array of SMonLogItem
  int32_t          maxLogs;
  const char      *server;
  uint16_t         port;
} SMonitor;

#ifdef __cplusplus
}
#endif

#endif /*_TD_MONITOR_INT_H_*/
