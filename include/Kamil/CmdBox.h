#ifndef KAMIL_CMDBOX_H
#define KAMIL_CMDBOX_H

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
