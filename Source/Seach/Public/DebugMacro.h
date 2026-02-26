#pragma once

#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,36,FColor::Red,true)

#define DRAW_SPHERE_COLOR(Location,Color) DrawDebugSphere(GetWorld(),Location,8.f,36,Color,false,5.f)

#define DRAW_LINE(StartLocation,EndLocation)if(GetWorld()) DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, true, -1.f, 0, 1.f);

#define DRAW_POINT(Location) if(GetWorld())DrawDebugPoint(GetWorld(), Location, 20, FColor::Blue, true);

#define DRAW_VECTOR(StartLocation,EndLocation)if(GetWorld())\
{\
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, true, -1.f, 0, 1.f);\
		DrawDebugPoint(GetWorld(), EndLocation, 20, FColor::Blue, true);\
}
#define DRAW_VECTOR(StartLocation, EndLocation) if (GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 1.f); \
		DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Red, true); \
	}

// 第二个宏：只显示一帧的向量（通常放在 Tick 函数里，随移动实时更新）
#define DRAW_VECTOR_SingleFrame(StartLocation, EndLocation) if (GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 1.f); \
		DrawDebugPoint(GetWorld(), EndLocation, 15.f, FColor::Red, false, -1.f); \
	}