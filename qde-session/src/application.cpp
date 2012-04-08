#include "application.h"
#include <unistd.h>
#include <stdlib.h>


Application::Application(int &argc, char **argv) :
	QdeCore::Application(tr("qde-session"), tr("QDE Session"), tr("QDE session manager"), argc, argv, false)
{
	setenv("XDG_MENU_PREFIX", "qde-", 1);
}
