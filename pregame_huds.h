#pragma once

const char* CONSOLE_FONT		= "fonts/720/consoleFont";
const char* NORMAL_FONT			= "fonts/720/normalFont";
const char* SMALL_FONT			= "fonts/720/smallFont";
const char* EXTRA_BIG_FONT		= "fonts/720/extraBigFont";
const char* BIG_DEV_FONT		= "fonts/720/bigDevFont";
const char* BOLD_FONT			= "fonts/720/boldFont";

struct Color_s
{
	float r, g, b, a;
	Color_s(float _r, float _g, float _b, float _a);
};

Color_s::Color_s(float r, float g, float b, float a)
{
	this->r = r / 255.0f;
	this->g = g / 255.0f;
	this->b = b / 255.0f;
	this->a = a / 255.0f;
}

Color_s themeColor = Color_s(128, 0, 128, 255);
Color_s red = Color_s(255, 0, 0, 255);
Color_s blue = Color_s(0, 0, 255, 255);
Color_s green = Color_s(0, 255, 0, 255);
Color_s purple = Color_s(128, 0, 128, 255);
Color_s pink = Color_s(254, 127, 156, 255);

bool menuIsOpen, parentMenu = false;
int currentMenu, scroll, maxScroll, scrollPosition, lastScrollPosition, wait;

enum sub_menus
{
	MainMenu,
	SubMenu1,
	SubMenu2,
	ThemeMenu
};