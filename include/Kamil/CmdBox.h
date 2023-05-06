#ifndef KAMIL_CMDBOX_H
#define KAMIL_CMDBOX_H

/**
 * @file Implementation file for the Command Box
 *
 * A Class that inherets from TextBox class and uses its constructor.
 * Meant to be sepereate to keep all Command Box related code away from the TextBox
 * since they only share similar function calls but handle events and text differently
 *
 */

#include "TextBox.h"

/**
 * @brief Class to handle the command TextBox
 */
class CmdBox : public TextBox
{
public:
    /**
     * @brief Using teh Parent class constructor
     */
    using TextBox::TextBox;
};
#endif // KAMIL_CMDBOX_H
