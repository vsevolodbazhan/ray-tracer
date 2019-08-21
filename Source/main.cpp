#include "Color/RGBColor.hpp"
#include "Core/Scene.hpp"
#include "Graphics/PPMImage.hpp"
#include "Math/Vector3D.hpp"
#include "Object/Camera.hpp"
#include "Object/Sphere.hpp"
#include "Surface/Material.hpp"

using namespace Color;
using namespace Core;
using namespace Graphics;
using namespace Math;
using namespace Object;
using namespace std;
using namespace Surface;

int main() {
  Material ivory{RGBColor(0.4, 0.4, 0.3)};
  Material red_rubber{RGBColor(0.3, 0.1, 0.1)};

  Scene scene(make_unique<PPMImage>(ImageProperties{1024, 768}));
  scene.AddShape(make_unique<Sphere>(ivory, Vector3D{-3, 0, -16}, 2));
  scene.AddShape(make_unique<Sphere>(red_rubber, Vector3D{-1, -1.5, -12}, 2));
  scene.AddShape(make_unique<Sphere>(red_rubber, Vector3D{1.5, -0.5, -18}, 3));
  scene.AddShape(make_unique<Sphere>(ivory, Vector3D{7, 5, -18}, 4));

  scene.Render("Example/Ambient");
}
