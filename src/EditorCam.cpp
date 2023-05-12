#include <Kamil/EditorCam.h>
#include <SFML/Graphics/RenderWindow.hpp>

EditorCam::EditorCam(sf::RenderWindow *window, float deltaScroll,
                     float deltaRotation, float deltaZoomIn, float deltaZoomOut)
    : window{window}, deltaScroll{deltaScroll}, deltaRotation{deltaRotation},
      deltaZoomIn{deltaZoomIn}, deltaZoomOut{deltaZoomOut} {}

void EditorCam::draw(sf::RenderTarget &target, sf::RenderStates states) const {}

void EditorCam::setCameraBounds(int width, int height) {
  camera = sf::View(sf::FloatRect(-50, 0, width, height));
}

void EditorCam::scrollUp() {
  float height = window->getView().getSize().y;
  auto camPos = camera.getCenter();
  // line limit
  if (camPos.y - height / 2 > 0) {
    camera.move(0, -deltaScroll);
  }
}

void EditorCam::scrollDown() {
  float height = window->getView().getSize().y;
  float bottomLimit = std::max(getBottomLimitPx(), height);
  auto camPos = camera.getCenter();
  if (camPos.y + height / 2 < bottomLimit + 20) {
    camera.move(0, deltaScroll);
  }
}

void EditorCam::scrollLeft() {
  float width = window->getView().getSize().x;
  auto camPos = camera.getCenter();
  // Scrolleo arriba si no me paso del limite izquierdo
  if (camPos.x - width / 2 > -marginXOffset) {
    camera.move(-deltaScroll, 0);
  }
}

void EditorCam::scrollRight() {
  float width = window->getView().getSize().x;
  float rightLimit = std::max(getRightLimitPx(), width);
  auto camPos = camera.getCenter();
  // Numero magico 20 como un plus
  if (camPos.x + width / 2 < rightLimit + 20) {
    camera.move(deltaScroll, 0);
  }
}

void EditorCam::rotateLeft() { camera.rotate(deltaRotation); }

void EditorCam::rotateRight() { camera.rotate(-deltaRotation); }

void EditorCam::zoomIn() { camera.zoom(deltaZoomIn); }

void EditorCam::zoomOut() { camera.zoom(deltaZoomOut); }

float EditorCam::getRightLimitPx() { return this->rightLimitPx; }

float EditorCam::getBottomLimitPx() { return this->bottomLimitPx; }

int EditorCam::getLineHeight() { return this->lineHeight; }
