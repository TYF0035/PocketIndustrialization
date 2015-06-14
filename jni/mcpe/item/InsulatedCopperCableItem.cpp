#include "InsulatedCopperCableItem.h"

int InsulatedCopperCableItem::_id = 2001;
InsulatedCopperCableItem* InsulatedCopperCableItem::itemInsulatedCopperCable = NULL;

InsulatedCopperCableItem::InsulatedCopperCableItem(int id) : Item(id - 256) {
	setNameID("insulatedCopperCable");
	setIcon("apple", 0);
	setCategory(2);
};

bool InsulatedCopperCableItem::useOn(ItemInstance *i, Player *player, int x, int y, int z, signed char, float, float, float) {
	i->count++;
};
