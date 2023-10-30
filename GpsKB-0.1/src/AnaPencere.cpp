/***************************************************************************
 *   Copyright (C) 2008 by Doğan Gölcük                                    *
 *   dogangolcuk@gmail.com                                                   *
 *                                                                         *
 ***************************************************************************/
#include "AnaPencere.h"

/// Customizing of code for Dialog.ui
AnaPencere::AnaPencere()
{
	setupUi(this);
}

/// Set max range on ComDial
/** Must set max as n-1 to account for index being zero based.
 */
void AnaPencere::setDialMax(int max)
{
	ComDial->setMaximum( max - 1);
}

//

