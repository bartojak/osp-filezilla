#ifndef __QUEUEVIEW_SKIPPED_H__
#define __QUEUEVIEW_SKIPPED_H__

#include "queueview_failed.h"

class CQueueViewSkipped : public CQueueViewFailed
{
public:
	CQueueViewSkipped(CQueue* parent, int index);

protected:

	DECLARE_EVENT_TABLE()
	void OnContextMenu(wxContextMenuEvent& event);
};

#endif //__QUEUEVIEW_SKIPPED_H__
