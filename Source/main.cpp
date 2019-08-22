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
  Material emerald{
    RGBColor(0.0215, 0.1745, 0.0215),
    RGBColor(0.07568, 0.61424, 0.07568),
    RGBColor(0.633, 0.727811, 0.633),
    0.6 * 128
  };

  Material ruby{
    RGBColor(0.1745, 0.01175, 0.01175),
    RGBColor(0.61424, 0.04136, 0.04136),
    RGBColor(0.727811, 0.626959, 0.62695),
    0.6 * 128
  };

  Scene scene(make_unique<PPMImage>(ImageProperties{1920, 1080}), Camera{{0, 0, 0}, 45});
  scene.AddShape(make_unique<Sphere>(emerald, Vector3D{-3, 0, -16}, 2));
  scene.AddShape(make_unique<Sphere>(ruby, Vector3D{-1, -1.5, -12}, 2));
  scene.AddShape(make_unique<Sphere>(ruby, Vector3D{1.5, -0.5, -18}, 3));
  scene.AddShape(make_unique<Sphere>(emerald, Vector3D{7, 5, -18}, 4));

  // lights.push_back(Light(Vec3f(-20, 20,  20), 1.5));
	//     lights.push_back(Light(Vec3f( 30, 50, -25), 1.8));
	//     lights.push_back(Light(Vec3f( 30, 20,  30), 1.7));

  scene.AddLight(make_unique<Light>(Vector3D{-20, 20, 20}, Intensity{0.1, 1.5, 1.5}));
  scene.AddLight(make_unique<Light>(Vector3D{30, 50, -25}, Intensity{0.1, 1.8, 1.8}));
  scene.AddLight(make_unique<Light>(Vector3D{30, 20, 30}, Intensity{0.1, 1.7, 1.7}));

  scene.Render("Example/Ambient (No AA)");
  scene.Render("Example/Ambient (AA)", true);
}
