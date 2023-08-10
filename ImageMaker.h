#ifndef IMAGEMAKER_H
#define IMAGEMAKER_H

#include <string>
#include <cmath>
#include <fstream>

const int MAX_WIDTH = 800;
const int MAX_HEIGHT = 800;
const int MAX_COLOR = 255;
enum COLOR { RED, GREEN, BLUE };

using namespace std;

class ImageMaker
{
public:
    // Constructor
    ImageMaker();
    // Parametrized Constructor
    ImageMaker(string filename);

    // Opens image with filename and stores information into

    /* Function: Load image with filename
     * Pre: Image file exists
     * Post: Image file unchanged after being loaded
     */
    void LoadImage(string filename);

    /*
     * Function: Save image colors into file
     * Pre: Colors are initialized and given to be written into file
     * Post: RGB Colors be written in order for each corresponding pixel
     */
    void SaveImage(string filename);

    // Size functions

    /*
     * Function: Getter function which returns the width in integer
     * Pre: Width is initialized
     * Post: Returns the width in integer if it was changed, if not it will
     *      returns 0. Width is unchanged
     */
    int GetWidth();

    /*
     * Function: Getter function which returns the height in integer
     * Pre: Height is initialized
     * Post: Returns the height in integer if it was changed, if not it will
     *      returns 0. Height is unchanged
     */
    int GetHeight();

    /*
     * Function: Setter function which initializes and sets the width with an integer
     * Post: Width is initialized with given parameter
     */
    void SetWidth(int width);

    /*
     * Function: Setter function which initializes and sets the height with an integer
     * Post: Height is initialized with given parameter
     */
    void SetHeight(int height);

    // Color functions
    /*
     * Function: Getter function to returns red pen value
     * Pre: Red pen value was initialized
     * Post: Return int value for red pen, no changes to variable
     */
    int GetPenRed();

    /*
     * Function: Getter function to returns green pen value
     * Pre: Green pen value was initialized
     * Post: Return int value for green pen, no changes to variable
     */
    int GetPenGreen();

    /*
     * Function: Getter function to returns blue pen value
     * Pre: Blue pen value was initialized
     * Post: Return int value for blue pen, no changes to variable
     */
    int GetPenBlue();

    /*
     * Function: Setter function for red pen color
     * Post: Initialized pen_red with an integer value
     */
    void SetPenRed(int newR);

    /*
     * Function: Setter function for green pen color
     * Post: Initialized pen_green with an integer value
     */
    void SetPenGreen(int newG);

    /*
     * Function: Setter function for blue pen color
     * Post: Initializes pen_blue with an integer value
     */
    void SetPenBlue(int newB);

    // Drawing methods
    // These methods will use the current red, green, blue values of the pen

    /*
     * Function: Drawing pixel function
     * Pre: x and y coordinates were not initialized
     * Post: Uses input parameter for x and y values to draw pixel
     */
    void DrawPixel(int x, int y);

    /*
     * Function: Drawing rectangle with x and y coordinates with two position inputs
     * Pre: x and y coordinates of each position were not initialized
     * Post: Uses x and y values of each input to draw rectangle
     */
    void DrawRectangle(int x1, int y1, int x2, int y2);

    /*
     * Function: Drawing a line with x and y values with two position inputs
     * Pre: x and y coordinates of each position were not initialized
     * Post: Uses x and y values of each input to draw a straight line
     */
    void DrawLine(int x1, int y1, int x2, int y2);

private:
    int width;
    int height;
    int pen_red;    // Used by draw functions
    int pen_green;  // Used by draw functions
    int pen_blue;   // Used by draw functions
    bool PointInBounds(int x, int y);
    short image[MAX_WIDTH][MAX_HEIGHT][3];
};

#endif //IMAGEMAKER_H
