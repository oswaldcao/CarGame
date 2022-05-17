#ifndef sdl_highscore_h
#define sdl_highscore_h

#include<SDL_ttf.h>

using namespace std;

class Score_manager
{
public:
    ScoreManager();
    ScoreManager(string text_, SDL_Color text_color_, const char* filePath, int fontSize);
    ~ScoreManager();

    SDL_Rect get_destRect() const {return destRect;}
    int get_xpos() const {return destRect.x;}
    void set_xpos(const int& x) {destRect.x = x;}
    int get_ypos() const {return destRect.y;}
    void set_ypos(const int& y) {destRect.y = y;}
    void set_xypos(const int& x, const int& y) {destRect.x = x; destRect.y = y;}
    void set_font_size(const int& font_size_) {font_size = font_size_;}
    void set_text_color(const SDL_Color& color) {text_color = color;}

    void set_file_path(const char* filePath) {file_path = filePath;}
    void set_text(const string& text_) {text = text_;}

    void update();
    void draw();
private:
    string text;
    SDL_Color text_color ;
    SDL_Rect srcRect, destRect;
    const char* file_path;
    TTF_Font* font;
    SDL_Texture* texture;
    int font_size;

}

#endif // sdl_highscore_h
