#ifndef DEMOWINDOW_H_
#define DEMOWINDOW_H_

#include "Window.h"

class DemoWindow final : public Window {
protected:
	double _cube_angle { 0. }; //угл поворота куба равный 0
	double _cube_scale { 1.0 }; //масштаб куба равный 1

public:
	DemoWindow(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~DemoWindow() = default;

	virtual void setup_gl() override;
	virtual void render() override;
	virtual void update() override;
};

#endif /* DEMOWINDOW_H_ */
