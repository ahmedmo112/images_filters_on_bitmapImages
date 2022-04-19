/*
FCAI - Programing 1 - 2022 - Assignment 3
Program Name : Photoshop 
Program Description : Apply filters on images
 Author1: Ahmed Mohamed Hany 20210038
 Author2: ahmed Alaa Mohamed 20210027
 Author3: Omnia Magdy abdelnaby 20211018
 Date: 5-4-2022
 Version: 1.0
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char imgRGB[SIZE][SIZE][3];

void loadRGBImage();
void saveRGBImage();

void filter1();
void filter2();
void filter3();
void filter4();
void filter5();
void filter6();
void filter7();
void filter8();
void filter9();
void filtera();
void filterb();
void filterc();


int main()
{
     char userinput;
    bool runner = true;
    cout << "Ahlan ya user ya habiby\n";
    loadRGBImage(); //call load image function
    while (runner)
    {
        //choices of filters to apply
        cout << "Please select a filter to apply or 0 to exit:\n1-Black & White Filter\n2-Invert Filter\n"
             << "3-Merge Filter\n4-Flip Filter\n5-Rotate Image\n6-Darken and Lighten Image\n7-Detect Image Edges\n8-Enlarge Image\n"
             <<"9-Shrink Image\na-Mirror 1/2 IMage\nb-Shuffle Image\nc-Blur Image\ns-Save the image to a file\n0-Exit\n";
        cout << "Your Choice : ";
        cin >> userinput; // take from user his choice
        switch (userinput) //switch statment for the choice
        {
        case '1':
            filter1(); //call filter 1 function
            cout << "_________________Black & White Done____________________\n\n";
            break;
        case '2':
            filter2(); //call filter 2 function
            cout << "_________________Invert Done____________________\n\n";
            break;
        case '3':
            filter3(); //call filter 3 function
            cout << "_________________Merge Done____________________\n\n";
            break;
        case '4':
            filter4(); //call filter 4 function
            cout << "_________________Flip Done____________________\n\n";
            break;
        case '5':
            filter5(); //call filter 5 function
            cout << "_________________Rotate Done____________________\n\n";
            break;
        case '6':
            filter6(); //call filter 6 function
            cout << "_________________Darken and Lighten Done____________________\n\n";
            break;
        case '7':
            filter7(); //call filter 7 function
            cout << "_________________Detect Image Edge Done____________________\n\n";
            break;
        case '8':
            filter8(); //call filter 8 function
            cout << "_________________Enlarge Done____________________\n\n";
            break;
        case '9':
            filter9(); //call filter 9 function
            cout << "_________________Shrink Done____________________\n\n";
            break;
        case 'a':
            filtera(); //call filter a function
            cout << "_________________Mirror Done____________________\n\n";
            break;
        case 'b':
            filterb(); //call filter b function
            cout << "_________________shuffle Done____________________\n\n";
            break;
        case 'c':
            filterc(); //call filter c function
            cout << "_________________Blur Done____________________\n\n";
            break;
        case 's':
            saveRGBImage(); //call save image function
            cout << "_________________Saving File Done____________________\n\n";
            break;
        case '0':
            cout << "Thanks for using our Photoshop\n";
            runner = false; //stop the program runner
            break;

        default:
            cout<<"wrong input Please enter a vaild choice\n";
            break;
        }
    }

    return 0;
}



void loadRGBImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, imgRGB);
}

void saveRGBImage () {

   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, imgRGB);
}


void filter1(){
    int avg=0,sum=0;
  for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){

        avg += ((imgRGB[i][j][0]+imgRGB[i][j][1]+imgRGB[i][j][2])/3);
    }
  }


  avg = avg/(SIZE*SIZE);

  for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){
      for(int k=0; k < RGB; k++){
        sum += imgRGB[i][j][k];
      }
   
      sum =sum /3;
      // cout<<sum<<endl;
      if (sum < avg)
      {
        imgRGB[i][j][0] = 0;
        imgRGB[i][j][1] = 0;
        imgRGB[i][j][2] = 0;
      }else{
        imgRGB[i][j][0] = 255;
        imgRGB[i][j][1] = 255;
        imgRGB[i][j][2] = 255;

      }
      sum=0;

    }
  }
}

void filter2(){
    for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){
      for(int k=0; k < RGB; k++){
        imgRGB[i][j][k]= 255 - imgRGB[i][j][k];
      }

    }
  }
}

void filter3(){
    unsigned char image2[SIZE][SIZE][3];
    char imageFileName [100];
    cout<<"enter the image 2 file name : ";
    cin >> imageFileName; //get the file name from user
    strcat (imageFileName , ".bmp");
    readRGBBMP(imageFileName, image2); //to load the image

    for (int i = 0; i < SIZE; i++) { //row
        for (int j = 0; j< SIZE; j++) { //columns
            for (int k = 0; k < 3; k++)
            {
                int average = 0;
                average = (imgRGB[i][j][k] + image2[i][j][k])/2;  //get the average color by get the sum of two pictures pixel color and dividing by 2
                imgRGB[i][j][k]= average;                       // set the new value to image pixel
            }
        }
    }
}


void filter4(){
    int x =0;
   char input;//to choosen between Flip (h)orizontally or (v)ertically

   cout<<"Flip (h)orizontally or (v)ertically : ";
   cin>>input;

   if (input == 'v')
   {
    for(int i=0; i < SIZE; i++)
    {
     for(int j=0; j < SIZE/2; j++)
     {
         for (int k = 0; k < 3; k++)
         {
         
        // to Swap the first pixel with last pixel in the coulmn
            x = imgRGB[i][j][k];
            imgRGB[i][j][k]=imgRGB[i][SIZE-1-j][k];
            imgRGB[i][SIZE-1-j][k]= x;
         }

      }
    }
   }

   else if(input == 'h')
   {

   for(int i=0; i < SIZE/2; i++)
   {
     for(int j=0; j < SIZE; j++)
     {
         for (int k = 0; k < 3; k++)
         {
          
   // to Swap the first pixel with last pixel in the coulmn 
            x = imgRGB[i][j][k];
            imgRGB[i][j][k]=imgRGB[SIZE-1-i][j][k];
            imgRGB[SIZE-1-i][j][k]= x;
         }
      }
    }
   }
   
   else //to avoid error
   {
     cout<<"unvalid input!";
   }
}

void filter5(){
    int tmp, deg; //declear variables tmp and deg
    cout << "Please Choose Rotation Degree:\n1-90 degree\n2-180 degree\n3-270 degree\nyour choice: ";
    cin >> deg; //take from user what the degree he want to rotate
    for (int i = 0; i < deg; i++)
    {

        for (int i = 0; i < SIZE / 2; i++) //rows till half
        {
            for (int j = i; j < SIZE - i - 1; j++) //subtract rows from 255
            {
              for (int k = 0; k < 3; k++)
              {
                tmp = imgRGB[i][j][k]; //save the value of image 
                imgRGB[i][j][k] = imgRGB[SIZE - j - 1][i][k]; //get top left side pixel equal bottom left side pixel
                imgRGB[SIZE - j - 1][i][k] = imgRGB[SIZE - i - 1][SIZE - j - 1][k];//get bottom left side pixel equal bottom right side pixel
                imgRGB[SIZE - i - 1][SIZE - j - 1][k] = imgRGB[j][SIZE - i - 1][k];//get bottom right side equal top right side pixel
                imgRGB[j][SIZE - i - 1][k] = tmp;//get right side pixel equal top left side pixel that we save it at tmp
              }
            }
        }
    }
}

//darken
void darken()
{
  for (int i =0 ; i < SIZE ; i++){
    for ( int j = 0 ; j < SIZE ; j++){
        for (int k = 0; k < 3; k++)
        {  
            imgRGB[i][j][k]= imgRGB[i][j][k]/2;  //dividing each pixel color (image[i][j]) by 2
        }
    }
  }
}


// lighten
void lighten()
{
   for (int i =0 ; i < SIZE ; i++){
    for ( int j = 0 ; j < SIZE ; j++){
      int light ;
      for (int k = 0; k < 3; k++)
      {
      
      light = imgRGB[i][j][k] + (imgRGB[i][j][k]/2); //get 50% of pixel color (image[i][j]/2) + the original pixel color
      if ( light > 255)  //compare it with 255 incase light bigger than 255
      {
        imgRGB[i][j][k] = 255; //then set the color to 255
      }
      else 
      {
        imgRGB[i][j][k] = light ;
      }
      }
    }
  }
}

void filter6(){
    int choice ;
    cout<<"do you want to "<<endl<<" 1-darken" <<endl<<" 2-lighten"<<endl;
    cin>>choice;  //to choosen between darker(1) or lighter (2)

    if (choice == 1) 
    {
     darken();
    }
    else if (choice == 2)
    {
     lighten();
    }
    else  {
    cout<<"try again ";
    }
}

void filter7(){
   for (int i = 0; i < SIZE; i++)
   {
    for (int j = 0; j < SIZE; j++)
    {
     for (int k = 0; k < 3; k++)
      {
      if (abs(imgRGB[i][j+1][k]-imgRGB[i][j][k])>50 || abs(imgRGB[i+1][j][k]-imgRGB[i][j][k])>50){
        imgRGB[i][j][k]=rand();
      }
      else{
       imgRGB[i][j][k]=0;
      }
    
    }
   }
   }
}


//----------------------------
unsigned char img2[SIZE][SIZE][3] ;
int x=0,y=0;

void copyRGBimage(unsigned char img2[SIZE][SIZE][3]){
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
        for (int k = 0; k < 3; k++)
        {
        
            img2[i][j][k]=imgRGB[i][j][k];
        }
        
        }

    }
}

void enlargeFirstQ(){
    for (int i = 0; i < SIZE/2; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
        {
        imgRGB[x][y][k] = img2[i][j][k];
        imgRGB[x][y+1][k]= img2[i][j][k];
        imgRGB[x+1][y+1][k]= img2[i][j][k];
        imgRGB[x+1][y][k]= img2[i][j][k];
        }
        y+=2;
      }
      x+=2;
      y=0;
    }
}

void enlargeSecondQ(){
   for (int i = 0; i < SIZE/2; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
         for (int k = 0; k < 3; k++)
        {
        imgRGB[x][y][k] = img2[i][j][k];
        imgRGB[x][y+1][k]= img2[i][j][k];
        imgRGB[x+1][y+1][k]= img2[i][j][k];
        imgRGB[x+1][y][k]= img2[i][j][k];
        }
        y+=2;
      
      }
      x+=2;
      y=0;
    }
}

void enlargeThirdQ(){
   for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
        {
        imgRGB[x][y][k] = img2[i][j][k];
        imgRGB[x][y+1][k]= img2[i][j][k];
        imgRGB[x+1][y+1][k]= img2[i][j][k];
        imgRGB[x+1][y][k]= img2[i][j][k];
        }
        y+=2;
      }
      x+=2;
      y=0;
    }
}

void enlargefouthQ(){
  for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
         for (int k = 0; k < 3; k++)
        {
        imgRGB[x][y][k] = img2[i][j][k];
        imgRGB[x][y+1][k]= img2[i][j][k];
        imgRGB[x+1][y+1][k]= img2[i][j][k];
        imgRGB[x+1][y][k]= img2[i][j][k];
        }
        y+=2;
      }
      x+=2;
      y=0;
    }
}


void filter8(){
    int choice;
  
  copyRGBimage(img2);

  cout<<"choose which quarter you want to enlarge 1 , 2 , 3 or 4: ";
  cin>>choice;
  if (choice == 1)
  {
   enlargeFirstQ();
  }else if (choice == 2){
    enlargeSecondQ();
  }else if (choice == 3)
  {
    enlargeThirdQ();
  }else if (choice == 4)
  {
    enlargefouthQ();
  }else{
    cout<<"unvalid quarter number , Try again!\n";
  }
}

void filter9(){
    
}

void mirror_left(){
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE/2; j++)
    {
      for (int k = 0; k < 3; k++)
        {
      
      imgRGB[i][SIZE -j-1][k] = imgRGB[i][j][k];
        }
    }
    
  }

}

void mirror_right(){
 for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE/2; j++)
    {
     for (int k = 0; k < 3; k++)
        {
      imgRGB[i][j][k] =  imgRGB[i][SIZE -j-1][k];
        }
    }
    
  }
}
void mirror_upper (){
   for (int i = 0; i < SIZE/2; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      for (int k = 0; k < 3; k++)
        {
      imgRGB [SIZE -i-1][j][k] =imgRGB[i][j][k];
        }
    }
    
  }
}

void mirror_lower(){
 for (int i = 0; i < SIZE/2; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
     for (int k = 0; k < 3; k++)
        { 
       imgRGB[i][j][k] = imgRGB [SIZE -i-1][j][k];
        }
    }
    
  }


}

void filtera(){
    int x=0;
    cout << "1-left1/2\n2-right1/2\n3-upper1/2\n4-lower1/2\nplease choose type of mirror : ";
    cin>>x;

    if(x ==1){
      mirror_left();
    }else  if(x ==2){
      mirror_right();
    }else  if(x ==3){
      mirror_upper();
    }else  if(x ==4){
      mirror_lower();
    }else{
      cout<< "Wrong input";
    }
}

//-------------------
unsigned char Q1[4][128][128][3] ;

void saveEachQuarter(){
  x=0,y=0;
  for (int i = 0; i < SIZE/2; i++)
  {
    for (int j = 0; j < SIZE/2; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        
      Q1[0][x][y][k]=imgRGB[i][j][k];
      }
      
      y++;
    }
    x++;
    y=0;
  }
  x=0,y=0;
  for (int i = 0; i < SIZE/2; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
        for (int k = 0; k < 3; k++)
      {
        
      Q1[1][x][y][k]=imgRGB[i][j][k];
      }
        y++;
      }
      x++;
      y=0;
    }
    x=0,y=0;
    for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
      {
        
      Q1[2][x][y][k]=imgRGB[i][j][k];
      }
        y++;
      }
      x++;
      y=0;
  }

  x=0,y=0;
  for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
        for (int k = 0; k < 3; k++)
      {
        
      Q1[3][x][y][k]=imgRGB[i][j][k];
      }
        y++;
      }
      x++;
      y=0;
  }
}

void filterb(){
    saveEachQuarter();
    int choice[4];
    x=0,y=0;

  cout<<"Enter new order of Quarters: ";
  for (int i = 0; i < 4; i++)
  {
  cin>>choice[i];
  }

    for (int i = 0; i < SIZE/2; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
      {
        
        imgRGB[i][j][k] = Q1[choice[0]-1][x][y][k];
      }
        y++;
      }
      x++;
      y=0;
    }
    x=0,y=0;
    for (int i = 0; i < SIZE/2; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
         for (int k = 0; k < 3; k++)
      {
        
        imgRGB[i][j][k] = Q1[choice[1]-1][x][y][k];
      }

        y++;
      }
      x++;
      y=0;
    }

    x=0,y=0;

    for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for (int k = 0; k < 3; k++)
      {
        
        imgRGB[i][j][k] = Q1[choice[2]-1][x][y][k];
      }
        y++;
      }
      x++;
      y=0;
    }

    x=0,y=0;

    for (int i = (SIZE/2); i < SIZE; i++) {
      for (int j = (SIZE/2); j< SIZE; j++) {
         for (int k = 0; k < 3; k++)
      {
        
        imgRGB[i][j][k] = Q1[choice[3]-1][x][y][k];
      }
        y++;
      }
      x++;
      y=0;
    }
}

void filterc(){
    
}