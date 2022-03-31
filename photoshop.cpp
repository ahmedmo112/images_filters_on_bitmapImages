#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage ();
void saveImage ();

void filter1();
void filter2();
void filter3();
void filter4();
void filter5();
void filter6();

int main()
{
    char userinput;
    bool runner = true;
    cout<<"Ahlan ya user ya habiby\n";
    loadImage();
    while (runner)
    {  
        cout<<"Please select a filter to apply or 0 to exit:\n1-Black & White Filter\n2-Invert Filter\n"<<
        "3-Merge Filter\n4-Flip Filter\n5-Darken and Lighten Image\n6-Rotate Image\ns-Save the image to a file\n0-Exit\n";
        cout<<"Your Choice : ";
        cin>>userinput;
        switch (userinput)
        {
        case '1':
            filter1();
            cout<<"_________________Black & White Done____________________\n\n";
            break;
        case '2':
            filter2();
            cout<<"_________________Invert Done____________________\n\n";
            break;
        case '3':
            filter3();
            cout<<"_________________Merge Done____________________\n\n";
            break;
        case '4':
            filter4();
            cout<<"_________________Flip Done____________________\n\n";
            break;
        case '5':
            filter5();
            cout<<"_________________Darken and Lighten Done____________________\n\n";
            break;
        case '6':
            filter6();
            cout<<"_________________Rotate Done____________________\n\n";
            break;
        case 's':
            saveImage();
            cout<<"_________________Saving File Done____________________\n\n";
            break;
        case '0':
            cout<<"Thanks for using our Photoshop\n";
            runner = false;
            break;
        
        default:
            break;
        }
    }

    return 0;
}



void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Please enter file name of the image to process: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//Ahmed Alaa 
void filter1(){

}

//Ahmed M. Hany
void filter2(){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j]=255-image[i][j];        
        }
    }
}

//Omnia
void filter3(){

}

//Ahmed Alaa
void filter4(){

}

//Ahmed M. Hany
void filter5(){

}

//Omnia
void filter6(){

}


