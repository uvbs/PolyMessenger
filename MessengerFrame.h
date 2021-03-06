/*
Copyright (C) 2014 by Joachim Meyer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#pragma once
#include <PolycodeUI.h>
#include "ToolWindows.h"

class ChatFrame;
class ConnectionWindow;
class ConnectionHandler;

class MessengerFrame : public UIElement {
public:
	MessengerFrame();
	~MessengerFrame();

	void showChat(String address);
	void newChat(String address);
	ChatFrame* getChatForAddress(String address);

	void showModal(UIWindow* modal);
	void hideModal();

	TextInputPopup *showTextInput(String caption, String action, String value);

	void Resize(int width, int height);
	void handleEvent(Event *e);

	ConnectionHandler *getConnections();

private:
	std::vector<ChatFrame*> chatFrames;
	ChatFrame* visibleChat;


	UIButton *connBtn;

	ConnectionWindow *connWin;
	TextInputPopup *textPopup;

	UIElement* modalRoot;
	UIRect *modalBlocker;
	UIWindow *modalChild;
};

