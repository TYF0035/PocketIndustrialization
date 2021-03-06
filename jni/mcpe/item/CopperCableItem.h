#pragma once
#include "Item.h"
#include "ItemInstance.h"

class CopperCableItem: public Item {
public:
	static int _id;
	static CopperCableItem* itemCopperCable;
	
public:
	CopperCableItem(int);
	
	bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
};
