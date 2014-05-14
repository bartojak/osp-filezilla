#include <filezilla.h>
#include "queue.h"
#include "queueview_skipped.h"
#include "Options.h"

BEGIN_EVENT_TABLE(CQueueViewSkipped, CQueueViewFailed)
EVT_CONTEXT_MENU(CQueueViewSkipped::OnContextMenu)
END_EVENT_TABLE()

CQueueViewSkipped::CQueueViewSkipped(CQueue* parent, int index)
	: CQueueViewFailed(parent, index, _("Skipped transfers"))
{
	std::list<ColumnId> extraCols;
	extraCols.push_back(colTime);
	CreateColumns(extraCols);
}

void CQueueViewSkipped::OnContextMenu(wxContextMenuEvent& event)
{
	wxMenu* pMenu = wxXmlResource::Get()->LoadMenu(_T("ID_MENU_QUEUE_SKIPPED"));
	if (!pMenu)
		return;

	bool has_selection = HasSelection();

	pMenu->Enable(XRCID("ID_REMOVE"), has_selection);
	pMenu->Enable(XRCID("ID_REQUEUE"), has_selection);
	pMenu->Enable(XRCID("ID_REQUEUEALL"), !m_serverList.empty());

	PopupMenu(pMenu);

	delete pMenu;
}

