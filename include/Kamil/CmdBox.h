#ifndef KAMIL_CMDBOX_H
#define KAMIL_CMDBOX_H

/**
 * @file Implementation file for the Command Box
 *
 * A Class that inherets from TextBox class and uses its constructor.
 * Meant to be sepereate to keep all Command Box related code away from the
 * TextBox since they only share similar function calls but handle events and
 * text differently.
 *
 * @bug event system issue
 *
 * The sfml event system acts as one and stores all text related events together.
 * When I get the text of the event into seperate strings it gives me the same text
 * not sure how to get around this for now.
 *
 */

#include "TextBox.h"

/**
 * @brief Class to handle the command TextBox
 */
class CmdBox : public TextBox {
public:
  /**
   * @brief Using the Parent class constructor
   * \image html CmdBox/CmdBox.png
   * \image latexCmdBox/CmdBox.eps
   */
  using TextBox::TextBox;
};
#endif // KAMIL_CMDBOX_H
