#include "application.h"
#include <QtCore/QLocale>
#include <QtCore/QTranslator>


QDE_CORE_NS_BEGIN

Application::Application(const QString &name, const QString &label, const QString &description, int &argc, char **argv, bool GUIenabled) :
	QApplication(argc, argv, GUIenabled)
{
	QApplication::setApplicationName(label);
	QApplication::setApplicationVersion(version());
}

QString Application::version() const
{
	static const QString res = QString::fromLatin1("0.0.1");
	return res;
}

void Application::transate()
{
	QTranslator qtTranslator;
	qtTranslator.load(QString::fromLatin1("qt_").append(QLocale::system().name()), QApplication::applicationDirPath());
	installTranslator(&qtTranslator);

	QTranslator appTranslator;
	qtTranslator.load(QString::fromLatin1("app_").append(QLocale::system().name()), QApplication::applicationDirPath());
	installTranslator(&appTranslator);
}

QDE_CORE_NS_END
