#pragma once

void drawHuds()
{
	drawText("BO2 14.1736.11 Hook", 595, 90, 0.65, Color_s(255, 255, 255, 255), SMALL_FONT, 2); // Draw Pregame Menu Title

	drawShader(500, 100, 300, 100 + (30 * maxScroll), Color_s(0, 0, 0, 180), "white", 0); // Draw Background Shader

	drawShader(500, 100, 2, 100 + (30 * maxScroll), Color_s(themeColor), "white", 2); // Draw Left Bar

	drawShader(800, 100, 2, 100 + (30 * maxScroll), Color_s(themeColor), "white", 2); // Draw Right Bar
	
	switch(currentMenu) // you can change submenu name in pregame_huds.h
	{
		case MainMenu:  // Main Menu 
			addOption(0, "Sub Menu 1");
			addOption(1, "Sub Menu 2");
			addOption(2, "Theme Menu");
		break;
		case SubMenu1: // Sub Menu 1
			addOption(0, "Option 1");
			addOption(1, "Option 2");
			addOption(2, "Option 3");

			parentMenu = MainMenu;
		break;
		case SubMenu2: // Sub Menu 2
			addOption(0, "Option 1");
			addOption(1, "Option 2");
			addOption(2, "Option 3");

			parentMenu = MainMenu;
		break;
		case ThemeMenu: // Sub Menu 3
			addOption(0, "Red Theme");
			addOption(1, "Blue Theme");
			addOption(2, "Green Theme");
			addOption(3, "Purple Theme");
			addOption(4, "Pink Theme");

			parentMenu = MainMenu;
		break;
	}
}

void ButtonMonitoring()
{
	wait++;
	if(wait > 10)
	{
		if (GetAsyncKeyState(VK_INSERT))
		{
			if(menuIsOpen != true)
			{
				menuIsOpen = true;
			}

			wait = 0;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			Execute();

			wait = 0;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			Exit();
			scrollPosition = 0;

			wait = 0;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			scrollPosition--;
			if (scrollPosition < 0) scrollPosition = maxScroll;

			wait = 0;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			scrollPosition++;
			if (scrollPosition > maxScroll) scrollPosition = 0;

			wait = 0;
		}
	}
}

void initMenu()
{
	if(menuIsOpen) drawHuds();
	ButtonMonitoring();
}