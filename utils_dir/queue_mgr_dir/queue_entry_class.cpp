/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../phwang.h"
#include "queue_entry_class.h"

QueueEntryClass::QueueEntryClass() {
    memset(this, 0, sizeof (*this));
}

QueueEntryClass::~QueueEntryClass() {
}
