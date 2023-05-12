#ifndef KAMIL_EDITOR_CAM_H
#define KAMIL_EDITOR_CAM_H


/**
 * @file EditorCam.h
 * @brief Implementation of EditorCam class
 *
 * Contains methods to manipulate the camera for the Editor
 */




#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class EditorCam : public sf::Drawable {
public:

    /**
     * @brief Constructor for EditorCam
     * @param sf::RenderWindow* - pointer to main window
     * @param float - scrolling delta value
     * @param float - rotation delta value
     * @param float - zoom in delta value
     * @param float - zoom out delta value
     */
  EditorCam(sf::RenderWindow *window, float deltaScroll, float deltaRotation,
            float deltaZoomIn, float deltaZoomOut);

  /**
   * @breif move camera up
   * @param void
   * @return void
   */
  void scrollUp();

  /**
   * @breif move camera down
   * @param void
   * @return void
   */
  void scrollDown();
 
  /**
   * @breif move camera left
   * @param void
   * @return void
   */
  void scrollLeft();
 
  /**
   * @breif move camera right
   * @param void
   * @return void
   */
  void scrollRight();

  /**
   * @breif move camera to position
   * @param float - x value
   * @param float - y value
   * @return void
   */
  void scrollTo(float x, float y);

  /**
   * @breif rotate camera left 
   * @param void
   * @return void
   */
  void rotateLeft();
  
  /**
   * @breif rotate camera right
   * @param void
   * @return void
   */
  void rotateRight();

  /**
   * @breif zoom camera in 
   * @param void
   * @return void
   */
  void zoomIn();

  /**
   * @breif zoom camera out
   * @param void
   * @return void
   */
  void zoomOut();


  /**
   * @breif get bottom pixel limit 
   * @param void
   * @return float - pixel limit
   */
  float getBottomLimitPx();

  /**
   * @breif get right pixel limit 
   * @param void
   * @return float - pixel limit
   */
  float getRightLimitPx();

  /**
   * @breif get line height 
   * @param void
   * @return int - line height
   */
  int getLineHeight();

  /**
   * @brief set camera bounds
   * @param int - width
   * @param int - height
   * @return void
   */
  void setCameraBounds(int width, int height);

  /**
   * @brief draw to window
   * @param sf::RenderTarget& - render target reference
   * @param sf::RenderStates - rendr states
   * @return void
   */
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
  sf::RenderWindow *window;        /**< refernce to window */
  sf::View camera;                 /**< handles camera manipulation */
  float deltaScroll;               /**< delta tiem for scrolling */
  float deltaRotation;             /**< delta time for rotation */
  float deltaZoomIn, deltaZoomOut; /** delta time for zoomin/out */
  float rightLimitPx;              /**< right pixel limit */
  float bottomLimitPx;              /**< bottom pixel limit */
  float lineHeight;                 /**< line height */
  int marginXOffset;                /**< margin offset */
};

#endif // KAMIL_EDITOR_CAM_H
