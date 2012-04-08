#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <QdeCore/Application>


class Application : public QdeCore::Application
{
public:
	Application(int &argc, char **argv);
};

#endif /* APPLICATION_H_ */
