/*
 * MIT License
 *
 * Copyright (c) 2025 Benoit Pelletier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "Interfaces/DungeonSaveInterface.h"
#include "ProceduralDungeonUtils.h"
#include "ProceduralDungeonLog.h"

void IDungeonSaveInterface::DispatchPreSaveEvent(UObject* Obj)
{
	check(IsValid(Obj));
	DungeonLog_Debug("[BEGIN] Dispatch 'Dungeon Pre Save' events from object '%s'.", *GetNameSafe(Obj));

	ObjectUtils::DispatchToObjectAndSubobjects(Obj, [](UObject* O) {
		if (IsValid(O) && O->Implements<UDungeonSaveInterface>())
		{
			IDungeonSaveInterface::Execute_PreSaveDungeon(O);
		}
	});

	DungeonLog_Debug("[END] Dispatch 'Dungeon Post Load' events from object '%s'.", *GetNameSafe(Obj));
}

void IDungeonSaveInterface::DispatchPostLoadEvent(UObject* Obj)
{
	check(IsValid(Obj));
	DungeonLog_Debug("[BEGIN] Dispatch 'Dungeon Post Load' events from object '%s'.", *GetNameSafe(Obj));

	ObjectUtils::DispatchToObjectAndSubobjects(Obj, [](UObject* O) {
		if (IsValid(O) && O->Implements<UDungeonSaveInterface>())
		{
			IDungeonSaveInterface::Execute_PostLoadDungeon(O);
		}
	});

	DungeonLog_Debug("[END] Dispatch 'Dungeon Post Load' events from object '%s'.", *GetNameSafe(Obj));
}
