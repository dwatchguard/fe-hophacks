// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here
#include <vector>
#include <string>
#include <stdio.h> 
#include <stdlib.h> 
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <queue>
#include "Weapon.h"
#include "Skill.h" 
#include "Position.h"
#include "State.h"
#include "Damage.h"
#include "Unit.h"
#include "SkillContext.h"
#include "Game.h"
#include "Cell.h"

#define NUMATTRIBUTES 8
#define ATTACK 0
#define MAGIC 1
#define DEFENSE 2
#define RESISTANCE 3
#define SKILL 4
#define SPEED 5
#define CHARISMA 6
#define CONSTITUTION 7