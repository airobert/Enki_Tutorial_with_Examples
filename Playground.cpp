
#include "Viewer.h"
#include <enki/PhysicalEngine.h>
#include <enki/robots/e-puck/EPuck.h>
#include <enki/robots/marxbot/Marxbot.h>
#include <enki/robots/thymio2/Thymio2.h>
#include <QApplication>
#include <QtGui>
#include <iostream>


using namespace Enki;
using namespace std;


class EnkiPlayground : public ViewerWidget
{
protected:
	QVector<EPuck*> epucks;
	QMap<PhysicalObject*, int> bullets;
	
public:
	EnkiPlayground(World *world, QWidget *parent = 0) :
		ViewerWidget(world, parent)
	{
		EPuck *epuck = new EPuck;
		epuck->pos = Point(20, 15);
		epuck->leftSpeed = 4;
		epuck->rightSpeed = 5;
		world->addObject(epuck);
		
		epuck = new EPuck;
		epuck->pos = Point(20, -10);
		epuck->leftSpeed = 5;
		epuck->rightSpeed = 2;
		epuck->setColor(Color(1, 0, 0));
		world->addObject(epuck);

		epuck = new EPuck;
		epuck->pos = Point(0, 30);
		epuck->leftSpeed = 2;
		epuck->rightSpeed = 3;
		epuck->setColor(Color(0, 1, 0));
		world->addObject(epuck);

	}
};

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	// Create the world and the viewer
	bool igt(app.arguments().size() > 1);

	QImage gt;
	
	World world(35, Color(0.9, 0.9, 0.9), World::GroundTexture());
	EnkiPlayground viewer(&world);
	
	viewer.show();
	
	return app.exec();
}

