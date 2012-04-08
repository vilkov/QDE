#ifndef QDE_CORE_NS_H_
#define QDE_CORE_NS_H_

#include <QtCore/qglobal.h>

#ifdef QDE_CORE_BUILD
#	define QDE_CORE_EXPORT Q_DECL_EXPORT
#else
#	define QDE_CORE_EXPORT Q_DECL_IMPORT
#endif

#define QDE_CORE_NS_BEGIN namespace QdeCore {
#define QDE_CORE_NS_END }

#endif /* QDE_CORE_NS_H_ */
