# Path tracing group 4

# Group
- Teodors Kerimovs
- Lauri Wilppu
- Verneri Hakkarainen
- Dang Ly

# Overview
This project is a ray tracer with basic features and a graphical user interface for image preview. Ray tracer is used to simulate light rays to make more realistic pictures. Our ray tracer features natural light from the sky or additionally from light source objects. Other features include different shapes: ball, box and rectangle. The camera is modifiable with changeable zoom, position, orientation, field of view and shutter speed for moving objects. The project also features different kinds of materials: matte colors, glossy (metal) colors and glass.
  The ray tracer is built on different classes working together: Rays, objects in the world, camera, and list of objects in the world. The rays travel from the camera to the objects like in many other ray tracers. The structure and code of this project is inspired heavily on Peter Shirley's book on the topic. (https://raytracing.github.io/v3/books/RayTracingInOneWeekend.html)
  The software we have implemented reads a .txt file and makes a 3D scene out of it. The rendered picture is outputted as .jpg. The GUI lets you see a preview of the world and of the camera position. Software is built using cmake and run through terminal. The rendering of the scene may take several minutes.

# How To Build

Please install cMake 3.20 or higher for building our raytracer project.

git clone https://version.aalto.fi/gitlab/kerimot1/cpp-pt-4.git
git submodule update --init

cd cpp-pt-4
mkdir build
cd build
cmake -DBUILD_RAYTRACER=ON -DBUILD_TESTS=ON ..
make

Run example scene:
./run_raytracer

Run custom scenes from scenes folder:
./run_raytacer ../scenes/cornell_box.txt

Run unit tests:
cd tests
./run_unit_tests

# Source code documentation
See folder doc for detailed documentation

# Credits
This project is developed as a group project of Aalto University ELEC-A7151 Object-oriented Programming with C++ course in 2023. The responsible teacher for the course was Yusein Ali, and the project advisor was Markus Säynevirta.

The project was developed by:
- Teodoros Kerimovs
- Lauri Wilppu
- Verneri Hakkarainen
- Dang Ly
