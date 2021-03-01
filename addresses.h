#pragma once

void* (*R_RegisterFont)(const char* name, int imageTrack) = (void* (*)(const char*, int))0x007332B0;
void(*R_AddCmdDrawText)(const char* text, int maxChars, void* font, float x, float y, float xScale, float yScale, float rotation, const float* color, int style) = (void(*)(const char*, int, void*, float, float, float, float, float, const float*, int))0x00710470;
void* (*Matrial_RegisterHandle)(const char* material, int imageTrack) = (void* (*)(const char*, int))0x00734000;
void(*R_AddCmdDrawStretchPic)(float x, float y, float w, float h, float s0, float t0, float s1, float t1, float* color, void* material) = (void(*)(float, float, float, float, float, float, float, float, float*, void*))0x00710080;

int(*G_LocalizedStringIndex)(const char* text) = (int(*)(const char*))0x004C6AB0;
int(*G_MaterialIndex)(const char* Material) = (int(*)(const char*))0x005ACF10;
void(*HudElem_DestroyAll)() = (void(*)())0x004A5660;
void(*Key_IsDown)(int ClientNum, int ButtonEnum) = (void(*)(int, int))0x992540;

void(*Cbuf_AddText)(int localClientNum, const char* text) = (void(*)(int, const char*))0x005BDF70;
void(*SV_GameSendServerCommand)(int localClientNum, int type, const char* cmd) = (void(*)(int, int, const char*))0x006B2920;