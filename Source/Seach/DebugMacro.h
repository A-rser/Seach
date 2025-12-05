#pragma once

#include "DrawDebugHelpers.h"

#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(),Location,25.f,36,FColor::Red,true)

#define DRAW_LINE(StartLocation,EndLocation)if(GetWorld()) DrawDebugLine(GetWorld(), Location, Location + Vector * 10000.f, FColor::Green, true, -1.f, 0, 1.f);

#define DRAW_POINT(Location) if(GetWorld())DrawDebugPoint(GetWorld(), Location, 20, FColor::Blue, true);

#define DRAW_VECTOR(StartLocation,EndLocation)if(GetWorld())\
{\
		DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Green, true, -1.f, 0, 1.f);\
		DrawDebugPoint(GetWorld(), EndLocation, 20, FColor::Blue, true);\
}