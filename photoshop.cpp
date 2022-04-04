#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE];

void loadImage();
void saveImage();

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
    cout << "Ahlan ya user ya habiby\n";
    loadImage();
    while (runner)
    {
        cout << "Please select a filter to apply or 0 to exit:\n1-Black & White Filter\n2-Invert Filter\n"
             << "3-Merge Filter\n4-Flip Filter\n5-Rotate Image\n6-Darken and Lighten Image\ns-Save the image to a file\n0-Exit\n";
        cout << "Your Choice : ";
        cin >> userinput;
        switch (userinput)
        {
        case '1':
            filter1();
            cout << "_________________Black & White Done____________________\n\n";
            break;
        case '2':
            filter2();
            cout << "_________________Invert Done____________________\n\n";
            break;
        case '3':
            filter3();
            cout << "_________________Merge Done____________________\n\n";
            break;
        case '4':
            filter4();
            cout << "_________________Flip Done____________________\n\n";
            break;
        case '5':
            filter5();
            cout << "_________________Rotate Done____________________\n\n";
            break;
        case '6':
            filter6();
            cout << "_________________Darken and Lighten Done____________________\n\n";
            break;
        case 's':
            saveImage();
            cout << "_________________Saving File Done____________________\n\n";
            break;
        case '0':
            cout << "Thanks for using our Photoshop\n";
            runner = false;
            break;

        default:
            break;
        }
    }

    return 0;
}

void loadImage()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Please enter file name of the image to process: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void saveImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

// Ahmed Alaa
void filter1()
{
    double avg, sum;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum += image[i][j];
        }
    }
    avg = sum / (SIZE * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j] > avg)
            {
                image[i][j] = 255;
            }
            else
            {

                image[i][j] = 0;
            }
        }
    }
}

// Ahmed M. Hany
void filter2()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = 255 - image[i][j];
        }
    }
}

// Omnia
void filter3()
{
    unsigned char image2[SIZE][SIZE];
    char imageFileName [100];
    cout<<"enter the image 2 file name : ";
    cin >> imageFileName;
    strcat (imageFileName , ".bmp");
    readGSBMP (imageFileName, image2);
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
                int average = 0;
        average =(image [i][j] + image2 [i][j])/2;
        image[i][j]= average;
        }
    }

}

// Ahmed Alaa
void filter4()
{
 int x =0;
   char input;
   cout<<"Flip (h)orizontally or (v)ertically : ";
   cin>>input;
   if (input == 'v')
   {
    for(int i=0; i < SIZE; i++){
     for(int j=0; j < SIZE/2; j++){

        x = image[i][j];
        image[i][j]=image[i][SIZE-1-j];
        image[i][SIZE-1-j]= x;
      }
   }
   }else if(input == 'h'){

   for(int i=0; i < SIZE/2; i++){
     for(int j=0; j < SIZE; j++){

        x = image[i][j];
        image[i][j]=image[SIZE-1-i][j];
        image[SIZE-1-i][j]= x;
      }
   }
   }else
   {
     cout<<"unvalid input!";
   }
}

// Ahmed M. Hany
void filter5()
{
    int tmp, deg;
    cout << "Please Choose Rotation Degree:\n1-90 degree\n2-180 degree\n3-270 degree\nyour choice: ";
    cin >> deg;
    for (int i = 0; i < deg; i++)
    {

        for (int i = 0; i < SIZE / 2; i++)
        {
            for (int j = i; j < SIZE - i - 1; j++)
            {
                tmp = image[i][j];
                image[i][j] = image[SIZE - j - 1][i];
                image[SIZE - j - 1][i] = image[SIZE - i - 1][SIZE - j - 1];
                image[SIZE - i - 1][SIZE - j - 1] = image[j][SIZE - i - 1];
                image[j][SIZE - i - 1] = tmp;
            }
        }
    }
}

// Omnia
void filter6()
{

}
