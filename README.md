
# About

This project is a simple 2D game engine developed in C++ designed for creating platformer games. It leverages SDL2 for graphics and window management, SDL2_image for handling images, SDL2_ttf for text rendering, and Box2D for physics and collision detection.

![App Screenshot](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExOWZrZDEwMjlsZjM0bXlvcnVzZ2tlejlrdHdzY2tmYTNzcjc0MWt6NCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/SdoJBOLm544quv8m4U/giphy.gif)

### Manually build from source code

- Clone repository `git clone https://github.com/mwlky/Avoidant.git`
- go to directory `cd Avoidant/Game`
- create directory `mkdir Build`
- enter directory `cd Build`
- compile project with `cmake ..`
- build with `cmake --build . --target Game -j`
- Enjoy!

## SDL2, SDL2 ttf, SDL2 Image Installation

#### This project requires installed SDL2 and Box2D packages to work properly.

If you're using a Debian-based system, such as Ubuntu

- Update package list `sudo apt-get update`
- Get the required packages `sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libbox2d-dev`

If you're using an Arch-based systems

- Update package list `sudo pacman -Syu`
- Get the required packages `sudo pacman -S sdl2 sdl2_image sdl2_ttf box2d`

## Platform Availability

As of now, Avoidant is primarily designed for Linux-based systems. The installation instructions for required packages on Debian, Arch, and Ubuntu systems have been provided earlier in this documentation.

## Windows Support

While the current focus is on Linux, the project is open to collaboration and contributions from the community to extend support for Windows. If you are a Windows user interested in helping adapt Avoidant to work seamlessly on your platform, your contributions and insights would be greatly appreciated. Feel free to reach out and collaborate with the project maintainers.

Your support and contributions will play a key role in making Avoidant accessible to a broader audience. Thank you for your interest and involvement in enhancing this project!

## License

This project is licensed under the MIT License, allowing you to use, modify, and distribute the code freely.
