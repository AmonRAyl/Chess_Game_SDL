# Chess_Game_SDL
A chess game made in SDL.  
I have combined the [game logic](https://github.com/AmonRAyl/Simple-Chess "Game Logic") and the [SDL board](https://github.com/AmonRAyl/SDL_CHESS "SDL BOARD") that I made in previous projects, correcting some errors.  
  
## How to use it with Visual Studio 2019:  
Download [SDL](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php) and [SDL images](https://lazyfoo.net/tutorials/SDL/06_extension_libraries_and_loading_other_image_formats/index.php) then:  
Has to be used with Debug x64 (the default could be x86).    
### Go to Project Properties:  
  
##### Add in Include Directories:
\...\SDL2-2.0.22\include  
\...\SDL2_image-2.6.1\include  
#### VC++ Directories:  
##### Add in Library Directories: 
\...\SDL2-2.0.22\lib\x64  
\...\SDL2_image-2.6.1\lib\x64  
#### Linker:
##### Input:
###### Add in Additional Dependencies:
SDL2.lib  
SDL2main.lib  
SDL2_image.lib  
  
You will have to add certain environment rules in your computer follow step 8 from [this](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/windows/msvc2019/index.php), you'll have to add 2 rules \...\SDL2-2.0.22\lib\x64 and \...\SDL2_image-2.6.1\lib\x64  
  
Finally download the images folder and copy it in your project directory, it will be at the same level as the Debug folder.  

### Missing rules:  
#### Tie by repetition  
#### Tie by 50 moves  
