#pragma once
#include "Item.h"
#include "ItemInstance.h"

class CopperCableItem: public Item {
public:
	static int _id;
	static CopperCableItem* itemCopperCable;
	
public:
	CopperCableItem(int);
	
	bool useOn(ItemInstance *itemStack, Player *player, int x, int y, int z, signed char sch1, float f1, float f2, float f3);
};
