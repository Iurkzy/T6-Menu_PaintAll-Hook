#pragma once

void drawText(const char* text, float x, float y, float scale, Color_s Color, const char* font, int imageTrack)
{
	R_AddCmdDrawText(text, 0x7FFFFFFF, R_RegisterFont(font, imageTrack), x, y, scale, scale, 0, (float*)&Color, 0);
}

void drawShader(int x, int y, int width, int height, Color_s Color, const char* material, int imageTrack)
{
	R_AddCmdDrawStretchPic(x, y, width, height, 0, 0, 0, 0, (float*)&Color, Matrial_RegisterHandle(material, imageTrack));
}

void addOption(int index, const char* text)
{
	drawText(text, 510, 140 + (index * 35), (scrollPosition == index) ? 0.75 : 0.65, (scrollPosition == index) ? themeColor : Color_s(255, 255, 255, 255), SMALL_FONT, 2);
	maxScroll = index;
}

Color_s ChangeTheme(Color_s Color)
{
	themeColor = Color;
	return Color;
}

void Execute()
{
	if (currentMenu == MainMenu)
	{
		if(scrollPosition == 0)
		{
			currentMenu = SubMenu1;

			scrollPosition = 0;
		}
		else if (scrollPosition == 1)
		{
			currentMenu = SubMenu2;

			scrollPosition = 0;
		}
		else if (scrollPosition == 2)
		{
			currentMenu = ThemeMenu;

			scrollPosition = 0;
		}
	}
	else if (currentMenu == ThemeMenu)
	{
		if(scrollPosition == 0)
		{
			ChangeTheme(red);
		}
		else if (scrollPosition == 1)
		{
			ChangeTheme(blue);
		}
		else if (scrollPosition == 2)
		{
			ChangeTheme(green);
		}
		else if (scrollPosition == 3)
		{
			ChangeTheme(purple);
		}
		else if (scrollPosition == 4)
		{
			ChangeTheme(pink);
		}
	}
}

void Exit()
{
	if (currentMenu == MainMenu)
	{
		menuIsOpen = false;
	}
	else
	{
		currentMenu = parentMenu;
	}
}