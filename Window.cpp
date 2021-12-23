#include <string>
#include <stdexcept>
#include "Window.h"

Window::Window(int width, int height)
: _width(width), _height(height)
{
	using namespace std::literals;

	_Window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
					"��������",
					DEFAULT_X, DEFAULT_Y,
					width, height,
					SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL),
			SDL_DestroyWindow);
    
	if (_Window == nullptr)
		throw std::runtime_error(
				"�� ������� ������� ����: "s + SDL_GetError());
        
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,0);
	_gl_context = std::shared_ptr<void>(
			SDL_GL_CreateContext(_Window.get()),
			SDL_GL_DeleteContext);
    
	if (_gl_context == nullptr)
		throw std::runtime_error(
				"�� ������� ������� �������� OpenGL: "s + SDL_GetError());
}

void Window::main_loop() {
	setup();
	setup_gl();

	SDL_Event event;
	auto keys = SDL_GetKeyboardState(nullptr);

	for(;;) {
		while (SDL_PollEvent (&event)) {
			if (event.type == SDL_QUIT)
				return;
			handle_event(event);
		}
		
		handle_keys(keys);
		update();
		render();
		SDL_GL_SwapWindow(_Window.get());
	}
}
