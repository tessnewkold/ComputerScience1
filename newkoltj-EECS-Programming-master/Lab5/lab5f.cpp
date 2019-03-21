#include <iostream>

using namespace std;

void line(int w, char fc){                          //function for drawing a single line 
    for(int i = 1; i <= w; i++){
        cout << fc; 
    }
        return;
    }

void solidRectangle(int w, int h, char fc){           //function for drawing a solid rectangel 
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cout << fc;
    }
    cout << endl;
    }
    return;
    }
    
void framedRectangle(int w, int h, char fc, int fw){          //function for drawing an empty rectangle
    int i;
    int j;
    for(i = 1; i <= h, i++;){                                               //for top lines (as wide as the frame width is declared)
        for(j = 1; j <= w; j++){
            if (j > fw && j <= (h-fw)){
            cout << " ";
        }
            else{
                cout << fc;
            } 
    }
    cout << endl;
}
return;
}
     

void square(int s, char fc){                             //function for drawing a sqare
    for(int i = 1; i <= s; i++){
        for(int j = 1; j <= s; j++){
            cout << fc;
    }
    cout << endl;
    }
    return;
    }


int main(){                                                     //main function
    int chooseShape;
    cout << "Welcome to Picture Maker!" << endl;
    cout << "Which shape should I draw (choose 1-4 and 0 to exit menu)? ";
    cin >> chooseShape;
    cout << endl;
                                                                //user will pick a shape to draw based on question above
    switch(chooseShape){                                        //this switch statement will execute statements btw 1-4
        case 1:                                                 //case 1 will draw a line with user choice of a character
    {
            int width = 0;
            char fill_char;
            cout << "Line Drawing!" << endl;
            cout << "Fill Character? ";
            cin >> fill_char;
            cout << endl;
            cout << "Width? ";
            cin >> width;
            cout << endl;
            line(width, fill_char);
            cout << endl;
            break;
    }
 
        case 2:                                                 //this case will output a solid rectangle
        {
            int width = 0;
            int height = 0;
            char fill_char;
            cout << "Solid Rectangle Drawing!" << endl;
            cout << "Fill Character?";
            cin >> fill_char;
            cout << endl;
            cout << "Width? ";
            cin >> width;
            cout << endl;
            cout << "Height? ";
            cin >> height;
            cout << endl;
            solidRectangle(width, height, fill_char);
            cout << endl;
            break;
    }

        case 3:                                                 //this case will return an empty rectangle
        {
            int width = 0;
            int height = 0;
            char fill_char;
            int frame_width = 0;
            cout << "Framed Rectangle!!" << endl;
            cout << "Frame Character? ";
            cin >> fill_char;
            cout << endl;
            cout << "Width? ";
            cin >> width;
            cout << endl;
            cout << "Height? ";
            cin >> height;
            cout << endl;
            cout << "Frame Width? ";
            cin >> frame_width;
            cout << endl;
            framedRectangle(width, height, fill_char, frame_width);
            cout << endl;
            break;
        }
        
        case 4:                                                     //this will return a square which is a rectangle with equal sides
        {
            int size = 0; 
            char fill_char;
            cout << "Square!" << endl;
            cout << "Character to use? ";
            cin >> fill_char;
            cout << endl;
            cout << "Side Length? ";
            cin >> size;
            cout << endl;
            square(size, fill_char);
            cout << endl;
            break;
        }
        case 0:{                                                        //switch statement will exit the program if user types 0
            cout << "Exiting!" << endl;
            break;
        }
        default:{                                                       //if the user does not type 0-4 it will prompt to pick again
            cout << "Not valid! Must pick value between 1-4 or 0 to exit.";
            break;
    }
    }
    
    cout << "Which shape should I draw (choose 1-4 and 0 to exit menu)? ";      //program asks again which shape to draw
    cin >> chooseShape;
    cout << endl;
    return 0;
}