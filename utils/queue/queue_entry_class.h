/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#ifndef QUEUE_ENTRYCLASS_H
#define QUEUE_ENTRYCLASS_H

class QueueEntryClass {
public:
	QueueEntryClass();
	~QueueEntryClass();

    QueueEntryClass *next;
    QueueEntryClass *prev;
    //Object *data;
    
    void clear();
};

#endif
