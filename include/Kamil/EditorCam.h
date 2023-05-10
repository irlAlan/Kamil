#ifndef KAMIL_EDITOR_CAM_H
#define KAMIL_EDITOR_CAM_H



#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class EditorCam : public sf::Drawable
{
public:
    EditorCam(sf::RenderWindow* window, float deltaScroll, float deltaRotation, float deltaZoomIn, float deltaZoomOut);
    void scrollUp();
    void scrollDown();
    void scrollLeft();
    void scrollRight();

    void scrollTo(float x, float y);

    void rotateLeft();
    void rotateRight();

    void zoomIn();
    void zoomOut();

    float getBottomLimitPx();
    float getRightLimitPx();
    int getLineHeight();

    void setCameraBounds(int width, int height);

    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;

private:
    sf::RenderWindow* window;
    sf::View camera; /**< handles camera manipulation */
        float deltaScroll; /**< delta tiem for scrolling */
        float deltaRotation; /**< delta time for rotation */
        float deltaZoomIn, deltaZoomOut; /** delta time for zoomin/out */
        float rightLimitPx;
        float bottomLimitPx;
        float lineHeight; 
        int marginXOffset;
};

#endif // KAMIL_EDITOR_CAM_H
