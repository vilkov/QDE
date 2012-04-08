#include "application.h"
#include <unistd.h>


Application::Application(int &argc, char **argv) :
	QdeCore::Application(tr("qde-session"), tr("QDE Session manager"), tr(""), argc, argv, false)
{

}
