#ifndef __CSCREEN_H__
#define __CSCREEN_H__
#include <windows.h>

/*
Класс исключения для класса CScreen
*/

class CSScreenException {
public:
	CSScreenException(int _err) : err(_err){}
	const char* what();
	int err;
};

/*
Класс CScreen содержит системозависимые вызовы для вывода на консоль.

Данная реализация предназначена для ОС MS Windows 2000 Professional
и более поздних.

Система координат:
	(0, 0)  - левый верхний угол экрана
	ось X   - горизонтально вправо
	ось Y   - вертикально вниз (положительное направление)
*/

class CScreen {
public:
	CScreen();
	~CScreen();
	void cursor_show(bool visible);
	void text_attr(WORD attr);
	void pos(int x, int y, char = 0);

	void pos_str(int x, int y, const char *str);

	void cls();

private:
	HANDLE hConsoleOutput;
	CONSOLE_CURSOR_INFO oldCursorInfo, curCursorInfo;
	WORD oldTextAttr;
};

#endif