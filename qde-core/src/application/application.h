#ifndef QDE_CORE_APPLICATION_H_
#define QDE_CORE_APPLICATION_H_

#include <QtGui/QApplication>
#include "../qde_core_ns.h"


QDE_CORE_NS_BEGIN

class QDE_CORE_EXPORT Application : public QApplication
{
public:
	Application(const QString &name, const QString &label, const QString &description, int &argc, char **argv, bool GUIenabled = true);

	QString version() const;
	static Application *instance() { return static_cast<Application*>(QApplication::instance()); }

protected:
	void transate();
};

QDE_CORE_NS_END

#endif /* QDE_CORE_APPLICATION_H_ */
