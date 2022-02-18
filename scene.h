#ifndef SCENE_H
#define SCENE_H
namespace myScene
{
    class Scene{
        public:
            Scene(){
                startCurses();
            }
            ~Scene(){
                endCurses();
            }
            void startCurses();
            void endCurses();
            int getInput();
            void sceneUpdate();
            void setSize(int, int);
            int getSize();
            void print_menu(WINDOW*, int);
        private:
            int termSize;
    };
}

#endif
