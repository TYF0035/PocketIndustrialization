#pragma once
#include "Item.h"
#include "ItemInstance.h"

class InsulatedCopperCableItem: public Item {
public:
	static int _id;
	static InsulatedCopperCableItem* itemInsulatedCopperCable;
	
public:
	InsulatedCopperCableItem(int);
	
	bool useOn(ItemInstance*, Player*, int, int, int, signed char, float, float, float);
};
