#include "Color/RGBColor.hpp"
#include "Core/Scene.hpp"
#include "Graphics/PPMImage.hpp"
#include "Illumination/Light.hpp"
#include "Math/Vector3D.hpp"
#include "Object/Camera.hpp"
#include "Object/Sphere.hpp"
#include "Surface/Material.hpp"

using namespace Color;
using namespace Core;
using namespace Graphics;
using namespace Illumination;
using namespace Math;
using namespace Object;
using namespace std;
using namespace Surface;

int main() {
  Material ivory{
    RGBColor(0.4, 0.4, 0.3), 0.0, 0.6, 0.3, 0.1, 0.0, 1.0, 200
  };
  Material red_rubber{
    RGBColor(0.3, 0.1, 0.1), 0.0, 0.9, 0.1, 0.0,  0.0, 1.0, 40
  };
  Material mirror{
    RGBColor(1.0, 1.0, 1.0), 0.0, 0.0, 10.0, 0.8, 0.0, 1.0, 5700
  };
  Material glass{
    RGBColor(0.6, 0.7, 0.8), 0.0, 0.0, 0.5, 0.1, 0.8, 1.5, 500
  };

  Scene scene(make_unique<PPMImage>(ImageProperties{1920, 1080}), Camera{{0, 0, 0}, 45});
  scene.AddShape(make_unique<Sphere>(ivory, Vector3D{-3, 0, -16}, 2));
  scene.AddShape(make_unique<Sphere>(glass, Vector3D{-1, -1.5, -12}, 2));
  scene.AddShape(make_unique<Sphere>(red_rubber, Vector3D{1.5, -0.5, -18}, 3));
  scene.AddShape(make_unique<Sphere>(mirror, Vector3D{7, 5, -18}, 4));

  scene.AddLight(make_unique<Light>(Vector3D{-20, 20, 20}, 1.5));
  scene.AddLight(make_unique<Light>(Vector3D{30, 50, -25}, 1.8));
  scene.AddLight(make_unique<Light>(Vector3D{30, 20, 30}, 1.7));

  scene.Render("Example/No AA");
  scene.Render("Example/AA", true);
}
